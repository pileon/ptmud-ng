# PTMUD-NG design

Like all complex programs at least a modicum of design will go a long way
to improve the quality of the program.

This document contains five main sections that describe some of the
requirements and design decisions made for PTMUD-NG:

* [Requirements](#Requirements) - General requirements
* [Networking](#Networking) - Working networking is quite crucial in a networked system
* [World](#World) - How is the MUD "world" organized?
* [Database](#Database) - Data needs to be stored
* [Utility](#Utility) - We need a set of utility components as well

## Requirements

* PTMUD-NG is *text-based*. All output will be text in one form or another,
  and all input will be handled as line-based commands
* As a member of the DikuMUD family, PTMUD-NG is geared toward "hack-n-slash"
  D&D type games
* The role-playing mechanics will be built into the game engine itself,
  but should be relatively easy to modify and tweak

## Networking

### Networking requirements

* We must be able to handle multiple simultaneously connected players
* We should be able to handle multiple types of network communication
  (IPv4, IPv6, local networking, perhaps even local terminal I/O)
* We should be able to handle multiple application-level protocols
  (e.g. HTTML, plain Telnet, common MUD-specific protocols on top of Telnet)
* Each connected player is connected to a unique in-game character

### Concepts

To implement the requirements we have three main concepts:
* Servers - The passive server-connection part where players connect to
* Connections - The active server-connection part handling buffering etc.
* Protocols - The application-level protocol handling for a connection

### Interaction

The configuration can list multiple servers (passive incomming connection
points) where players can use their tool of choice to connect to.

When the game is running, all current servers are polled for new connections,
and all current connections are polled for input. During this polling all
queued output for a connection will be flushed.

When a connection to a server is made, it creates a connection handler and a
protocol handler.

If a connection have input then the protocol handler fetches it from from the
connection, parses it and creates a queue of commands. The main game event loop
will fetch one command at a time (one command per connection poll round) to
pass to the game command interpreter.

## World

<sub>This section describes the "classes" for the world. For the mechanics of
the game and itw world, please see [the mechanics document](mechanics.md).</sub>

The world is divided into three parts: Areas, zones and locations.

An area can have one or more zones, and a zone could have zero or more
locations.

Each area will have recommended character levels.

In each location there could be zero or more items or "monsters" (NPC's, non-
playing characters). A location could have zero or more exits to other
locations.

### Classes and implementation

Implementation-wise, everything in the world shares a common ancestor, and are
part of the same inheritance hierarchy.

In C++ parlance:
* `class thing;`
* `class area : public thing;`
* `class zone : public thing;`
* `class location : public thing;`
* `class character : public thing;`
* `class monster : public character;`
* `class player : public character;`
* `class wizard : public character;`
* `class item : public thing;`

All NPC's will be a type of `monster`.

All items will be a type of `item`.

The `monster` and `item` classes will be leaf-classes in the inheritance tree:
Instead of using inheritance to derive e.g. a `sword` from a `weapon` from
`item`, it's behavior-based and use multiple inheritance.

For example common bags will inherit from `item` and `container`, meaning it's
an item that can contain other items. A wizard NPC will be a `monster` and a
`spell_caster`, meaning it's a NPC that can cast spells.

## Database

## Utility
