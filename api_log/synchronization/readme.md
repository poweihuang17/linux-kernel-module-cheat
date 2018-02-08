# Synchronization API exercise

## Atomic operation
- [x] atomic\_add()
- [x] atomic\_dec()
- [x] atomic\_add\_negative()
- [x] atomic\_add\_return()
- [x] atomic\_set()
- [x] atomic\_read()
- [x] atomic\_inc()
- [x] atomic\_inc\_and\_test()
- [x] atomic\_add\_unless()
- [x] atomic\_cmpxchg()
- [x] atomic\_dec\_and\_test()

### Comment
- Easy to understand. It has various form of API to support syntax like while. For example, inc\_and\_test is an example.

### Atomic bit operation
Similar to atomic operation, so I skip it now.

## Semaphore operation
- [x] down()
- [ ] down\_interruptible()
- [ ] down\_killable()
- [ ] down\_timeout()
- [ ] down\_trylock()
- [x] sema\_init()
- [ ] up()

## Read/Write Semaphore operation 
- [ ] down\_read()
- [ ] down\_read\_trylock()
- [ ] down\_write()
- [ ] down\_write\_trylock()
- [ ] downgrade\_write()
- [ ] init\_rwsem()
- [ ] up\_read()
- [ ] up\_write()

## Spinlock
Need example and excercise. It doesn't have examples in the book.
- [ ] spinlock_irqsave?

### Question about Spinlock
- I don't understand those about irqsave...Know very few about irq...

## Seqlock
- [x] read\_seqbegin()
- [x] read\_seqretry()
- [x] seqlock\_init()
- [x] write\_seqlock()
- [x] write\_sequnlock() 

### Question about Seqlock
- Why it favors write over read?
- Why do we need to use retry?
- What's the pros and cons of Seqlock over spinlock? Why does jiffies use this? It has a lot of write, right? Why does jiffies still use this in this case?
