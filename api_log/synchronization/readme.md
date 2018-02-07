# Synchronization API exercise

## Atomic operation
- atomic\_add()
- atomic\_dec()
- atomic\_add\_negative()
- atomic\_add\_return()
- atomic\_set()
- atomic\_read()
- atomic\_inc()
- atomic\_inc\_and\_test()
- atomic\_add\_unless()
- atomic\_cmpxchg()
- atomic\_dec\_and\_test()

### Comment
- Easy to understand. It has various form of API to support syntax like while. For example, inc\_and\_test is an example.

## Semaphore operation
- down()
- down\_interruptible()
- down\_killable()
- down\_timeout()
- down\_trylock()
- sema\_init()
- up()

## Read/Write Semaphore operation 
- down\_read()
- down\_read\_trylock()
- down\_write()
- down\_write\_trylock()
- downgrade\_write()
- init\_rwsem()
- up\_read()
- up\_write()

## Seqlock
- read\_seqbegin()
- read\_seqretry()
- seqlock\_init()
- write\_seqlock()
- write\_sequnlock() 

