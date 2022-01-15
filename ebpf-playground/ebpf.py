from bcc import BPF
from time import sleep


b = BPF(src_file="./ebpf.c")
clone = b.get_syscall_fnname("clone")
b.attach_kprobe(event=clone, fn_name="hello_world")
# b.trace_print()

while True:
    sleep(2)
    s = ""
    if len(b["clones"].items()):
        for k, v in b["clones"].items():
            s += f"ID {k.value}: {v.value}\t"
        print(s)
    else:
        print("No entries yes")
