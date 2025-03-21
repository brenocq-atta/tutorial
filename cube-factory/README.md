<!--
title: Cube Factory
description: How to create multiple clones of the same entity using prototypes
image: https://storage.googleapis.com/atta-images/docs/tutorial/cube-factory/cube-factory.gif
build: https://atta-repos.s3.us-east-1.amazonaws.com/tutorial/cube-factory
-->
# Cube Factory

<div align="center">
  <img src="https://storage.googleapis.com/atta-images/docs/tutorial/cube-factory/cube-factory.gif" height="400">
</div>

This project is an introduction to atta prototypes, and they are a key feature to simulate multi-robot systems.

The whole idea behind prototypes is having multiple clones of the same thing. Because they are identical, atta can efficiently organize them in memory and paralelize the execution of their scripts.

This project create an wave animation using clones of a cube entity.

## Prototype-Clone-Factory
First, let's understand the difference between prototype, clone, and factory.

**Prototypes** are entities used as **template** to create **clone entities**. Prototype entities don't interact with other entities during the simulation and their scripts are not executed either.

**Clones** are entities that were generated from a prototype entity. Each clone entity has a copy of the prototype entity's components as its components.

The **factory** is the responsible for creating the clones from the prototype, and providing an interface to obtain information about the clones and prototypes. For example, we need to use the factory to access the EntityId of each clone generated by a prototype.

<div align="center">
  <img src="https://storage.googleapis.com/atta-images/docs/tutorial/cube-factory/factory.png" height="200">
</div>

## Setting up
Now that we understand what they are, let's see how to add them to the project.

We will add a prototype component to the cube, where we can specity the number of clones (`maxClones`) to be created. Note that the cube will not be rendered anymore.

<div align="center">
  <img src="https://storage.googleapis.com/atta-images/docs/tutorial/cube-factory/prototype_component.png" height="350">
</div>

If we press the `start button`, clones should be generated. They will all be in the same position, let's change that with the script.

## Implementation details
The components from the clones generated by the same prototype are continuously stored in the memory, which reduces cache misses and makes it possible to do only one transfer to the GPU.
