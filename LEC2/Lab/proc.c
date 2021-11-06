// get the number of processes whose state is not UNUSED
int
nproc()
{
  int n = 0;
  struct proc *p;
  for(p = proc; p < &proc[NPROC]; p++) {
    acquire(&p->lock);
    if(p->state != UNUSED)
      n++;
    release(&p->lock);
  }
  return n;
}
