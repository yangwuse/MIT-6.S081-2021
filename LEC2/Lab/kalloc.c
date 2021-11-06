// get the number of bytes of free memory
int 
freemem() 
{
  struct run *pg = kmem.freelist;
  uint64 n = 0;
  while(pg) {
    n++;
    pg = pg->next;
  }
  return n * PGSIZE;
}
