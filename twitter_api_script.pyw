from tweepy import OAuthHandler
from tweepy import Stream
from tweepy.streaming import StreamListener
import time
import tweepy
import codecs
import json


rFile = open("keywords.txt", "r")
keywords_load = rFile.read()
rFile.close()

keywords = []
s = list(keywords_load)
index = 0
b = ""

while index < len(keywords_load):
    if s[index] is not '\n':
        b += s[index]
        index += 1
    elif s[index] is '\n':
        keywords.append(b)
        b = ""
        index += 1
    


start_time = time.time() #grabs the system time

con_key = '7XpxGvmepgHwWnh4BtVeGha7K'
con_secret = 'dZv0o74iXY57CLPrTw61abrfWjSGg070MNy0MJkotzoNAMgmjM'
acc_token = '2257769054-IBxxhkqmBFWSOqcq7JR9UnHnQDMZdR6IcCFcxNg'
acc_token_secret = 'ujQrQ74xnxpGa40mixTq8RLBjfMiKWr4fP4EEy4MzNanK'


auth = OAuthHandler(con_key, con_secret)
auth.set_access_token(acc_token, acc_token_secret)

api = tweepy.API(auth)

def parse_json_tweet(line):
    tweet = json.loads(line)
    
    if tweet['lang'] != 'en':
        return ['']

    if 'retweeted_status' in tweet:
        text = tweet['retweeted_status']['text']
    else:
        text = tweet['text']
              

    return [text]

class listener(StreamListener):
 
    def __init__(self, start_time, time_limit=60):
 
        self.time = start_time
        self.limit = time_limit
        self.tweet_data = []
 
    def on_data(self, data):
        
        saveFile = codecs.open('raw_tweets.json', 'a', encoding='utf-8')
        
        
        while (time.time() - self.time) < self.limit:
 
            try:
                self.tweet_data.append(data)
                return True
 
 
            except BaseException as e:
                print ('failed ondata,' + str(e))
                time.sleep(0.5)
                pass
 
        saveFile = codecs.open('raw_tweets.json', 'w', encoding='utf-8')
        
        saveFile.write(u'[\n')
        saveFile.write(''.join(self.tweet_data))
        saveFile.write(u'\n]')
        saveFile.close()
        print("\nTwitter streamfile created")
        
        file_timeordered_json_tweets = codecs.open("raw_tweets.json", 'r', 'utf-8')
        fout = codecs.open("tweet_content.txt", 'w', 'utf-8')
        
        for line in file_timeordered_json_tweets:
            try:
                [text] = parse_json_tweet(line)
                
                fout.write(str(text))
                
                
            except: 
                pass
        fout.write("[STREND]")
        file_timeordered_json_tweets.close()
        fout.close()

        print("\nTwitter textfile created")
        exit()
        
    def on_error(self, status):
        print (status)


twitterStream = Stream(auth, listener(start_time, time_limit=10)) #initialize Stream object with a time out limit
twitterStream.filter(track=keywords, languages=['en'])  #call the filter method to run the Stream Object

