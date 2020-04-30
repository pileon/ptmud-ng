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

## Spells

## Character creation

## Character level up

## Violence

Being a "hack-n-slash" type game, violence, fighting and offensive (as well as
defensive) actions are a big part of the game.

It will be a configuration option if PvP (Player versus Player) fighting will
be allowed, or if the game is a PvE (Player versus Environment) game.
A PvE game could allow restricted and limited PvP in certain locations.
