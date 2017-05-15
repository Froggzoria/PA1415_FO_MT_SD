#include "Catalogue.h"

Catalogue::Catalogue()
{
	//Read from .txt file?
	this->pRace[0].setName("Dwarf");
	this->pRace[0].setDescription("Dwarves are smaller than humans or elves, but are stocky and solid individuals.\n Dwarves' most notable trait is their great expertise in mining and metalwork.\n Dwarvish armor is said to be second in quality not even to the mithril armor \nof the Elves.");
	this->pRace[1].setName("Elf");
	this->pRace[1].setDescription("Elves are agile, quick, and perceptive; very little of what goes on will escape an Elf.\nThe quality of Elven craftsmanship often gives them an advantage in arms and armor.");
	this->pRace[2].setName("Gnome");
	this->pRace[2].setDescription("Gnomes are smaller than but generally similar to dwarves. Gnomes are known to be\n expert miners, and it is known that a secret underground mine complex built \nby this race exists within the Mazes of Menace, filled with both riches and danger.");
	this->pRace[3].setName("Human");
	this->pRace[3].setDescription("Humans are by far the most common race of the surface world, and are thus the norm\n by which other races are often compared. Although they have no special \nabilities, they can succeed in any role.");
	this->pRace[4].setName("Orc");
	this->pRace[4].setDescription("Orcs are a cruel and barbaric race that hate every living thing (including other orcs).\n Above all others, Orcs hate Elves with a passion unequalled, and will\n go out of their way to kill one at any opportunity.\n The armor and weapons fashioned by the Orcs are typically of inferior quality.");

	this->pClass[0].setName("Archeologist");
	this->pClass[0].setDescription("Archeologists understand dungeons pretty well; this enables them\n to move quickly and sneak up on the local nasties.\n They start equipped with the tools for a proper scientific expedition.");
	this->pClass[1].setName("Barbarian");
	this->pClass[1].setDescription("Barbarians are warriors out of the hinterland, hardened to battle.\n They begin their quests with naught but uncommon strength, \na trusty hauberk, and a great two-handed sword. ");
	this->pClass[2].setName("Caveman");
	this->pClass[2].setDescription("Cavemen and Cavewomen start with exceptional strength \nbut, unfortunately, with neolithic weapons");
	this->pClass[3].setName("Healer");
	this->pClass[3].setDescription("Healers are wise in medicine and apothecary. They know the herbs \nand simples that can restore vitality, ease pain, anesthetize, \nand neutralize poisons; and with their instruments, they can divine \na being's state of health or sickness. Their medical practice earns them \nquite reasonable amounts of money, with which they enter the dungeon. ");
	this->pClass[4].setName("Knight");
	this->pClass[4].setDescription("Knights are distinguished from the common skirmisher by their \ndevotion to the ideals of chivalry and by the surpassing excellence \nof their armor.");
	this->pClass[5].setName("Monk");
	this->pClass[5].setDescription("Monks are ascetics, who by rigorous practice of physical and mental \ndisciplines have become capable of fighting as effectively without \nweapons as with. They wear no armor but make up for it with increased mobility. ");
	this->pClass[6].setName("Priest");
	this->pClass[6].setDescription("Priests and Priestesses are clerics militant, crusaders advancing \nthe cause of righteousness with arms, armor, and arts thaumaturgic. \nTheir ability to commune with deities via prayer occasionally extricates \nthem from peril, but can also put them in it. ");
	this->pClass[7].setName("Ranger");
	this->pClass[7].setDescription("Rangers are most at home in the woods, and some say slightly \nout of place in a dungeon. They are, however, experts in archery \nas well as tracking and stealthy movement. ");
	this->pClass[8].setName("Rogue");
	this->pClass[8].setDescription("Rogues are agile and stealthy thieves, with knowledge of locks, \ntraps, and poisons. Their advantage lies in surprise, which \nthey employ to great advantage. ");
	this->pClass[9].setName("Samurai");
	this->pClass[9].setDescription("Samurai are the elite warriors of feudal Nippon. They are lightly \narmored and quick, and wear the dai-sho, two swords of the \ndeadliest keenness. ");
	this->pClass[10].setName("Tourist");
	this->pClass[10].setDescription("Tourists start out with lots of gold (suitable for shopping with), \na credit card, lots of food, some maps, and an expensive camera. \nMost monsters don't like being photographed. ");
	this->pClass[11].setName("Valkyrie");
	this->pClass[11].setDescription("Valkyries are hardy warrior women. Their upbringing in the harsh \nNorthlands makes them strong, inures them to extremes of cold, \nand instills in them stealth and cunning. ");
	this->pClass[12].setName("Wizard");
	this->pClass[12].setDescription("Wizards start out with a knowledge of magic, a selection of magical \nitems, and a particular affinity for dweomercraft. \nAlthough seemingly weak and easy to overcome at first sight, \nan experienced Wizard is a deadly foe. ");

	this->pAttributes[0].setName("Strength");
	this->pAttributes[0].setDescription("A measure of your character's strength; The higher your strength, \nthe stronger you are. Strength affects how successfully you \nperform physical tasks, how much damage you do in combat, \nand how much loot you can carry. ");
	this->pAttributes[1].setName("Dexterity");
	this->pAttributes[1].setDescription("Dexterity affects your chances to hit in combat, to avoid traps, \nand do other tasks requiring agility or manipulation of objects. ");
	this->pAttributes[2].setName("Constitution");
	this->pAttributes[2].setDescription("Constitution affects your ability to recover from injuries \nand other strains on your stamina. ");
	this->pAttributes[3].setName("Intelligence");
	this->pAttributes[3].setDescription("Intelligence affects your ability to cast spells and read spellbooks. ");
	this->pAttributes[4].setName("Wisdom");
	this->pAttributes[4].setDescription("Wisdom comes from your practical experience \n(especially when dealing with magic). It affects your magical energy. ");
	this->pAttributes[5].setName("Charisma");
	this->pAttributes[5].setDescription("Charisma affects how certain creatures react toward you. \nIn particular, it can affect the prices shopkeepers offer you. ");
}

Catalogue::~Catalogue()
{

}

std::string Catalogue::getRaceName(int index)
{
	return pRace[index].getName();
}

std::string Catalogue::getRaceDescription(int index)
{
	return pRace[index].getDescription();
}

std::string Catalogue::getClassName(int index)
{
	return pClass[index].getName();
}

std::string Catalogue::getClassDescription(int index)
{
	return pClass[index].getDescription();
}

std::string Catalogue::getAttributeName(int index)
{
	return this->pAttributes[index].getName();
}

std::string Catalogue::getAttributeDescription(int index)
{
	return this->pAttributes[index].getDescription();
}
