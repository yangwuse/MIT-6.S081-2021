// trace
uint64
sys_trace(void)
{
  if (argint(0, &myproc()->tracemask) < 0)
    return -1;
  return 0;
}

// collects information about the running system
uint64
sys_sysinfo(void)
{
  uint64 ptr; // user pointer to struct sysinfo
  struct sysinfo sinfo;
  struct proc *p = myproc();

  if (argaddr(0, &ptr) < 0)
    return -1;

  sinfo.freemem = freemem();
  sinfo.nproc = nproc();

  if ((copyout(p->pagetable, ptr, (char *)&sinfo, sizeof(sinfo)) < 0))
    return -1;
  
  return 0;
}
