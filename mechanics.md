# Game mechanics

The game mechanics of a role-playing game is always controversial. Should
it be based on an existing RPG mechanics? Which one should it then be based
on? If not, then how similar to other systems can we kmake it without
plagiarizing to much or risk copyright infringement?

As a DikuMUD variant, should PTMUD-NG strictly follow the DikuMUD mechanics,
which in turn were modeled (if not plainly copied from) AD&D, or should we
make up our own system? And if we make up our own system how much should we
deviate from the standard DikuMUD mechanisms?

To answer all those questions, PTMUD-NG will be using its own system, written
from scratch for PTMUD-NG. However due to the nature of RPG's, it might seem
similar or inspired by other systems, and will certainly have some common
concepts to other systems. The PTMUD-NG mechanics will be very different from
the "standard" DikuMUD mechanics in many ways.

While many systems use dice-rolls or equivalent mechanics, the PTMUD-NG system
will be designed to generally require simple random numbers between 0 and 100
(inclusive). These numbers could of course be made from rolling dice, but
won't be using "die" or "dice-roll" as terms.

## Levels and XP

PTMUD-NG will have levels and experience points (XP). There will not be a
(practical) limit to the number of levels though, and the amount of XP needed
for each level will be algorithmically calculated.

Experience points is primarily earned from fighting, but also from exploration.

## Classes

PTMUD-NG will be classless. Any player can pick any set of skills or spells for
progression.

## Attributes

Attributes in PTMUD-NG are the base character attributes, like strength or
dexterity.

All attributes will have a value from 1 (non-existant) to 100 (maxed out). It's
only possible to get zero or a negative value from affections from spells or
equipment.

Attributes for new characters should start in the range 10 to 20, and can be
increased with level-progression.

Attributes:
* Constitution
* Dexterity
* Intelligence
* Strength

### Constitution

A characters constitution dictates how much punishment the character can take.
How well does the character handles poisons? Melee damage?

It affect the characters health and how much health the character gains while
leveling up.

### Dexterity

The dexterity score tells how nimble or quick a character might be. With higher
dexterity the character could evade more melee attacks and move longer.
 
### Intelligence

Intelligence is important when learning spells and skills. The higher
intelligence the more spells and skills the character can learn, and the
quicker the character will learn them.

### Strength

Strength is the brute force of a character. It's important for being able to
cary large amount of heavy equipment, as well as for damaging foes with things
like clubs or bare hands.

## Health, movement and "mana"

Equipment can't put a characters health at or below zero, and non-offensive
spells can't directly put a characters health below zero.

When a character have zero health, the character is considered unconscious and
can't perform any in-game actions. If the character stays at zero health for
a time, the character will "bleed" and loose health until the character dies.

When a character reaches minus 10% of the max health of the character, the
character will die.

There's no upper limit in the health points.

## Skills

Skills are things a character can learn.

Some skills needs multiple rounds of training, while others are learned once.

Skills are handled as percentages. For skills that needs multiple sessions to
train, each training session adds a certain amount to the percentage knowledge.
For one-time training skills, the percentage will be immediately set to 100.

If a character have zero in a skill, it means the character has no knowledge
at all. But all characters can still use all skills, a zero percentage skill
will always fail unless the character have some luck-component which modifies
the skill check, or have some affection (through other skills, spells or
equipment) that modifies the skill percentage.

Training a multi-session skill becomes harder and harder the higher percentage
the character already knows the skill. Training from zero to 10 will be easy,
but from 90 to 100 will be extremely hard, and if the characters intelligence
isn't high enough can even fail. Learning skills is a logarithmic curve.

Skills are commonly taught by specific NPC teachers in the game, but can also
be trained through continuous and common usage. For the higher percentages
of a skill, practical use is almost always the best way to increase skill
knowledge.

## Spells

Spells are a special-case of skills: They are skills that needs to be trained
in multiple sessions, and can never be trained over 99%. Also, a zero-percent
spell can't be used at all, zero percent means that the character doesn't know
about the spell at all.

## Character creation

## Character level up

## Violence

Being a "hack-n-slash" type game, violence, fighting and offensive (as well as
defensive) actions are a big part of the game.

It will be a configuration option if PvP (Player versus Player) fighting will
be allowed, or if the game is a PvE (Player versus Environment) game.
A PvE game could allow restricted and limited PvP in certain locations.
