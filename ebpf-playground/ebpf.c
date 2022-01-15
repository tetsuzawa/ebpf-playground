BPF_HASH(clones);

int hello_world(void *ctx) {
    u64 uid;
    u64 counter = 0;
    u64 *p;

    uid = bpf_get_current_uid_gid() & 0xFFFFFFFF;
    p = clones.lookup(&uid);

    if ( p != 0 ) {
        counter = *p;
    }
    counter++;
    clones.update(&uid, &counter);

    // bpf_trace_printk("Hello world\n");
    bpf_trace_printk("id: %d\\n", uid);
    return 0;
}
