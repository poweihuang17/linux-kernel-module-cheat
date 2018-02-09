# Interrupt handling API exercis
e

## basic irq
- [ ] disable_irq()
- [ ] disable_irq_nosync()
- [ ] disable_irq_wake()
- [ ] enable_irq()
- [ ] enable_irq_wake()
- [x] free_irq()
- [ ] irq_set_chip()
- [ ] irq_set_chip_data()
- [ ] irq_set_irq_type()
- [ ] irq_set_irq_wake()
- [x] remove_irq()
- [x] request_irq()
- [x] request_threaded_irq()
- [x] setup_irq()

###  Comment
- The remaining APIs like irq_set_chip are quite boring. It's just about setting some parameters for irq devices or handlers. I'll skip it now.
- Enable and disable are just interrupt control. (Open or close interrupt line)

### Question:
- It seems that setup/remove and request/free are all about register interrupt.So, what's the difference.
- What's the meaning of IRQDISABLED, IRQSHOT, IRQSHARED? Why does IRQDISABLED being disabled?
- So, the request_threaded_irq means that it could have a kernel thread to continue working? Isn't it similar to buttom_half?
- What's 喚醒深度？
- disable_irq(), disable_irq_nosync(), disable_irq_wake(): What's the difference between these three api? There seems to be similar question for tasklet.
- What's enable_wake()?
- Why could the examples on book trigger handler once? I remembered that I couldn't get my handler triggered when I was working on request_irq.c.

### Problem:
- Right now, I don't have an emulated device, so there is no interrupt. I couldn't test my interrupt handler.

## tasklet
- [ ] tasklet_disable()
- [ ] tasklet_disable_nosync()
- [ ] tasklet_enable()
- [x] tasklet_hi_schedule()
- [x] tasklet_init()
- [x] tasklet_kill()
- [x] tasklet_schedule()
- [x] tasklet_trylock()
- [x] tasklet_unlock()
- [ ] __tasklet_hi_schedule()
- [ ] __tasklet_schedule()

### Questions:

- Why does tasklet execute after module_init? When will the tasklet execute?
- How to do I/O for interrupt handler and tasklet?
- Why do we need to use tasklet_trylock?
- Does the state of trylock have any special meaning?
- Why do we need a high schedule for tasklet? Isn't it weird?
- What's the difference between disable and disable_nosync?

### Problem
- Tasklet should be called and initialized within interrupt handler. But, I haven't written one of it.

## Softirq

## Workqueue

## Todo:
- What's special for interrupt handling? I think the magic comes from different devices, and we need different way and flags for different devices and different speed difference. Need to find out the magic later.
- Build a platform with emulated interrupt provider!

## Thought:
- Interrupt is not hard. Register->handler->tasklet schedule->tasklet execute. But I need to build a real-world interrupt handler that calls tasklet. It's important. 
- I think I should proceed to other chapters now.
