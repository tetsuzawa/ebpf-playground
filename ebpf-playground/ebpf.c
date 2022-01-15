int hello_world(void *ctx) {
    u64 uid;
    uid = bpf_get_current_uid_gid() & 0xFFFFFFFF;
    // bpf_trace_printk("Hello world\n");
    bpf_trace_printk("id: %d\\n", uid);
    return 0;
}
