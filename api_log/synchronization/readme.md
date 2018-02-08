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

## Atomic bit operation
Similar to atomic operation, so I skip it now.

## Semaphore operation
- [x] down()
- [x] down\_interruptible()
- [x] down\_killable()
- [x] down\_timeout()
- [x] down\_trylock()
- [x] sema\_init()
- [x] up()

### Problems about Semaphore
- I've written all of the code and could compile successfully, but I don't know how to test it. For example, I don't know how to send signal to it, and I don't know how to use the code to send signal as the book suggested. Probably had to test it later.

- Now(08:33 02/08/2018), I'm not sure whether I record all the log of test results before. But I will proceed.

### Question:
- What happen if a process goes into the state of sleep?
- If it couldn't be waken up by signal, how does it wake up?

## Read/Write Semaphore operation 
- [x] down\_read()
- [x] down\_read\_trylock()
- [x] down\_write()
- [x] down\_write\_trylock()
- [x] downgrade\_write()
- [x] init\_rwsem()
- [x] up\_read()
- [x] up\_write()

### Question about rw semaphore
- Given rwsemaphore has downgrade_write, why don't we have downgrade_write for read/write spinlock?

## Spinlock
Need example and excercise. It doesn't have examples in the book.
- [ ] spinlock_irqsave?

### Question about Spinlock
- I don't understand those about irqsave...Know very few about irq...

### Read/Write Spinlock

### Question about Read/Write Spinlock

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
- What's the advantage or difference of Seqlock over read/write Spinlock?

## RCU
-
