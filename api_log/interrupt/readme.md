# Interrupt handling API exercise

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

### Question:
- It seems that setup/remove and request/free are all about register interrupt.So, what's the difference.
- What's the meaning of IRQDISABLED, IRQSHOT, IRQSHARED? Why does IRQDISABLED being disabled?
- So, the request_threaded_irq means that it could have a kernel thread to continue working? Isn't it similar to buttom_half?

### Problem:
- Right now, I don't have an emulated device, so there is no interrupt. I couldn't test my interrupt handler.

## tasklet
- [ ] tasklet_disable()
- [ ] tasklet_disable_nosync()
- [ ] tasklet_enable()
- [ ] tasklet_hi_schedule()
- [ ] tasklet_init()
- [ ] tasklet_kill()
- [ ] tasklet_schedule()
- [ ] tasklet_trylock()
- [ ] tasklet_unlock()
- [ ] __tasklet_hi_schedule()
- [ ] __tasklet_schedule()

##Softirq
