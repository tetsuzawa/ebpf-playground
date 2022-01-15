from bcc import BPF
from time import sleep
import bcc


b = BPF(src_file="./ebpf.c")
clone = b.get_syscall_fnname("clone")
b.attach_kprobe(event=clone, fn_name="hello_world")
b.trace_print()
