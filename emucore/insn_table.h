#ifdef INSTRUCTION_TABLE
#include "insn.h"

insn_desc_t instructions[256] = {
    INSN_ENTRY(0x0, 1, 4, IMP_nop),
    INSN_blank(0x1, 1, 12, IMP_ld_0x1),
    INSN_ENTRY(0x2, 1, 8, IMP_insn_store_A),
    INSN_blank(0x3, 1, 8, IMP_inc_0x3),
    INSN_ENTRY(0x4, 1, 4, IMP_insn_incr8),
    INSN_blank(0x5, 1, 4, IMP_dec_0x5),
    INSN_ENTRY(0x6, 1, 8, IMP_insn_ld_immediate),
    INSN_blank(0x7, 1, 4, IMP_rlca_0x7),
    INSN_blank(0x8, 1, 20, IMP_ld_0x8),
    INSN_blank(0x9, 1, 8, IMP_add_0x9),
    INSN_ENTRY(0xa, 1, 8, IMP_insn_ld_indirect),
    INSN_blank(0xb, 1, 8, IMP_dec_0xb),
    INSN_ENTRY(0xc, 1, 4, IMP_insn_incr8),
    INSN_blank(0xd, 1, 4, IMP_dec_0xd),
    INSN_ENTRY(0xe, 1, 8, IMP_insn_ld_immediate),
    INSN_blank(0xf, 1, 4, IMP_rrca_0xf),
    INSN_blank(0x10, 1, 4, IMP_stop_0x10),
    INSN_blank(0x11, 1, 12, IMP_ld_0x11),
    INSN_ENTRY(0x12, 1, 8, IMP_insn_store_A),
    INSN_blank(0x13, 1, 8, IMP_inc_0x13),
    INSN_ENTRY(0x14, 1, 4, IMP_insn_incr8),
    INSN_blank(0x15, 1, 4, IMP_dec_0x15),
    INSN_ENTRY(0x16, 1, 8, IMP_insn_ld_immediate),
    INSN_blank(0x17, 1, 4, IMP_rla_0x17),
    INSN_ENTRY(0x18, 1, 8, IMP_jump_rel),
    INSN_blank(0x19, 1, 8, IMP_add_0x19),
    INSN_ENTRY(0x1a, 1, 8, IMP_insn_ld_indirect),
    INSN_blank(0x1b, 1, 8, IMP_dec_0x1b),
    INSN_ENTRY(0x1c, 1, 4, IMP_insn_incr8),
    INSN_blank(0x1d, 1, 4, IMP_dec_0x1d),
    INSN_ENTRY(0x1e, 1, 8, IMP_insn_ld_immediate),
    INSN_blank(0x1f, 1, 4, IMP_rra_0x1f),
    INSN_ENTRY(0x20, 1, 8, IMP_jump_rel),
    INSN_blank(0x21, 1, 12, IMP_ld_0x21),
    INSN_ENTRY(0x22, 1, 8, IMP_insn_store_A),
    INSN_blank(0x23, 1, 8, IMP_inc_0x23),
    INSN_ENTRY(0x24, 1, 4, IMP_insn_incr8),
    INSN_blank(0x25, 1, 4, IMP_dec_0x25),
    INSN_ENTRY(0x26, 1, 8, IMP_insn_ld_immediate),
    INSN_blank(0x27, 1, 4, IMP_daa_0x27),
    INSN_ENTRY(0x28, 1, 8, IMP_jump_rel),
    INSN_blank(0x29, 1, 8, IMP_add_0x29),
    INSN_ENTRY(0x2a, 1, 8, IMP_insn_ld_indirect),
    INSN_blank(0x2b, 1, 8, IMP_dec_0x2b),
    INSN_ENTRY(0x2c, 1, 4, IMP_insn_incr8),
    INSN_blank(0x2d, 1, 4, IMP_dec_0x2d),
    INSN_ENTRY(0x2e, 1, 8, IMP_insn_ld_immediate),
    INSN_blank(0x2f, 1, 4, IMP_cpl_0x2f),
    INSN_ENTRY(0x30, 1, 8, IMP_jump_rel),
    INSN_blank(0x31, 1, 12, IMP_ld_0x31),
    INSN_ENTRY(0x32, 1, 8, IMP_insn_store_A),
    INSN_blank(0x33, 1, 8, IMP_inc_0x33),
    INSN_ENTRY(0x34, 1, 12, IMP_insn_incr8),
    INSN_blank(0x35, 1, 12, IMP_dec_0x35),
    INSN_ENTRY(0x36, 1, 12, IMP_insn_ld_immediate),
    INSN_blank(0x37, 1, 4, IMP_scf_0x37),
    INSN_ENTRY(0x38, 1, 8, IMP_jump_rel),
    INSN_blank(0x39, 1, 8, IMP_add_0x39),
    INSN_ENTRY(0x3a, 1, 8, IMP_insn_ld_indirect),
    INSN_blank(0x3b, 1, 8, IMP_dec_0x3b),
    INSN_ENTRY(0x3c, 1, 4, IMP_insn_incr8),
    INSN_blank(0x3d, 1, 4, IMP_dec_0x3d),
    INSN_ENTRY(0x3e, 1, 8, IMP_insn_ld_immediate),
    INSN_blank(0x3f, 1, 4, IMP_ccf_0x3f),
    INSN_ENTRY(0x40, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x41, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x42, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x43, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x44, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x45, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x46, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x47, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x48, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x49, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x4a, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x4b, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x4c, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x4d, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x4e, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x4f, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x50, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x51, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x52, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x53, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x54, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x55, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x56, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x57, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x58, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x59, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x5a, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x5b, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x5c, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x5d, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x5e, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x5f, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x60, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x61, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x62, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x63, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x64, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x65, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x66, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x67, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x68, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x69, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x6a, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x6b, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x6c, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x6d, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x6e, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x6f, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x70, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x71, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x72, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x73, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x74, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x75, 1, 8, IMP_insn_ld8),
    INSN_blank(0x76, 1, 4, IMP_halt_0x76),
    INSN_ENTRY(0x77, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x78, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x79, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x7a, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x7b, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x7c, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x7d, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x7e, 1, 8, IMP_insn_ld8),
    INSN_ENTRY(0x7f, 1, 4, IMP_insn_ld8),
    INSN_ENTRY(0x80, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x81, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x82, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x83, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x84, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x85, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x86, 1, 8, IMP_insn_add8),
    INSN_ENTRY(0x87, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x88, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x89, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x8a, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x8b, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x8c, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x8d, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x8e, 1, 8, IMP_insn_add8),
    INSN_ENTRY(0x8f, 1, 4, IMP_insn_add8),
    INSN_ENTRY(0x90, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x91, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x92, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x93, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x94, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x95, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x96, 1, 8, IMP_insn_sub8),
    INSN_ENTRY(0x97, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x98, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x99, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x9a, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x9b, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x9c, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x9d, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0x9e, 1, 8, IMP_insn_sub8),
    INSN_ENTRY(0x9f, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0xa0, 1, 4, IMP_insn_and8),
    INSN_ENTRY(0xa1, 1, 4, IMP_insn_and8),
    INSN_ENTRY(0xa2, 1, 4, IMP_insn_and8),
    INSN_ENTRY(0xa3, 1, 4, IMP_insn_and8),
    INSN_ENTRY(0xa4, 1, 4, IMP_insn_and8),
    INSN_ENTRY(0xa5, 1, 4, IMP_insn_and8),
    INSN_ENTRY(0xa6, 1, 8, IMP_insn_and8),
    INSN_ENTRY(0xa7, 1, 4, IMP_insn_and8),
    INSN_ENTRY(0xa8, 1, 4, IMP_insn_xor8),
    INSN_ENTRY(0xa9, 1, 4, IMP_insn_xor8),
    INSN_ENTRY(0xaa, 1, 4, IMP_insn_xor8),
    INSN_ENTRY(0xab, 1, 4, IMP_insn_xor8),
    INSN_ENTRY(0xac, 1, 4, IMP_insn_xor8),
    INSN_ENTRY(0xad, 1, 4, IMP_insn_xor8),
    INSN_ENTRY(0xae, 1, 8, IMP_insn_xor8),
    INSN_ENTRY(0xaf, 1, 4, IMP_insn_xor8),
    INSN_ENTRY(0xb0, 1, 4, IMP_insn_or8),
    INSN_ENTRY(0xb1, 1, 4, IMP_insn_or8),
    INSN_ENTRY(0xb2, 1, 4, IMP_insn_or8),
    INSN_ENTRY(0xb3, 1, 4, IMP_insn_or8),
    INSN_ENTRY(0xb4, 1, 4, IMP_insn_or8),
    INSN_ENTRY(0xb5, 1, 4, IMP_insn_or8),
    INSN_ENTRY(0xb6, 1, 8, IMP_insn_or8),
    INSN_ENTRY(0xb7, 1, 4, IMP_insn_or8),
    INSN_ENTRY(0xb8, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0xb9, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0xba, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0xbb, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0xbc, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0xbd, 1, 4, IMP_insn_sub8),
    INSN_ENTRY(0xbe, 1, 8, IMP_insn_sub8),
    INSN_ENTRY(0xbf, 1, 4, IMP_insn_sub8),
    INSN_blank(0xc0, 1, 8, IMP_call_ret_absolute),
    INSN_ENTRY(0xc1, 1, 12, IMP_pop_pair),
    INSN_ENTRY(0xc2, 1, 12, IMP_jump_absolute),
    INSN_ENTRY(0xc3, 1, 12, IMP_jump_absolute),
    INSN_blank(0xc4, 1, 12, IMP_call_ret_absolute),
    INSN_ENTRY(0xc5, 1, 16, IMP_push_pair),
    INSN_blank(0xc6, 1, 8, IMP_add_0xc6),
    INSN_ENTRY(0xc7, 1, 16, IMP_rst_vec),
    INSN_blank(0xc8, 1, 8, IMP_call_ret_absolute),
    INSN_blank(0xc9, 1, 4, IMP_call_ret_absolute),
    INSN_ENTRY(0xca, 1, 12, IMP_jump_absolute),
    INSN_blank(0xcb, 1, 4, IMP_prefix_0xcb),
    INSN_blank(0xcc, 1, 12, IMP_call_ret_absolute),
    INSN_blank(0xcd, 1, 12, IMP_call_ret_absolute),
    INSN_blank(0xce, 1, 8, IMP_adc_0xce),
    INSN_ENTRY(0xcf, 1, 16, IMP_rst_vec),
    INSN_blank(0xd0, 1, 8, IMP_call_ret_absolute),
    INSN_ENTRY(0xd1, 1, 12, IMP_pop_pair),
    INSN_ENTRY(0xd2, 1, 12, IMP_jump_absolute),
    INSN_ENTRY(0xd3, 1, 0, IMP_undefined_instruction),
    INSN_blank(0xd4, 1, 12, IMP_call_ret_absolute),
    INSN_ENTRY(0xd5, 1, 16, IMP_push_pair),
    INSN_blank(0xd6, 1, 8, IMP_sub_0xd6),
    INSN_ENTRY(0xd7, 1, 16, IMP_rst_vec),
    INSN_blank(0xd8, 1, 8, IMP_call_ret_absolute),
    INSN_ENTRY(0xd9, 1, 16, IMP_reti),
    INSN_ENTRY(0xda, 1, 12, IMP_jump_absolute),
    INSN_ENTRY(0xdb, 1, 0, IMP_undefined_instruction),
    INSN_blank(0xdc, 1, 12, IMP_call_ret_absolute),
    INSN_ENTRY(0xdd, 1, 0, IMP_undefined_instruction),
    INSN_blank(0xde, 1, 8, IMP_sbc_0xde),
    INSN_ENTRY(0xdf, 1, 16, IMP_rst_vec),
    INSN_ENTRY(0xe0, 1, 12, IMP_insn_ld_absolute),
    INSN_ENTRY(0xe1, 1, 12, IMP_pop_pair),
    INSN_ENTRY(0xe2, 1, 8, IMP_insn_ld_absolute),
    INSN_ENTRY(0xe3, 1, 0, IMP_undefined_instruction),
    INSN_ENTRY(0xe4, 1, 0, IMP_undefined_instruction),
    INSN_ENTRY(0xe5, 1, 16, IMP_push_pair),
    INSN_blank(0xe6, 1, 8, IMP_and_0xe6),
    INSN_ENTRY(0xe7, 1, 16, IMP_rst_vec),
    INSN_blank(0xe8, 1, 16, IMP_add_0xe8),
    INSN_ENTRY(0xe9, 1, 4, IMP_jump_absolute),
    INSN_ENTRY(0xea, 1, 16, IMP_insn_ld_absolute),
    INSN_ENTRY(0xeb, 1, 0, IMP_undefined_instruction),
    INSN_ENTRY(0xec, 1, 0, IMP_undefined_instruction),
    INSN_ENTRY(0xed, 1, 0, IMP_undefined_instruction),
    INSN_blank(0xee, 1, 8, IMP_xor_0xee),
    INSN_ENTRY(0xef, 1, 16, IMP_rst_vec),
    INSN_ENTRY(0xf0, 1, 12, IMP_insn_ld_absolute),
    INSN_ENTRY(0xf1, 1, 12, IMP_pop_pair),
    INSN_ENTRY(0xf2, 1, 8, IMP_insn_ld_absolute),
    INSN_ENTRY(0xf3, 1, 4, IMP_edi),
    INSN_ENTRY(0xf4, 1, 0, IMP_undefined_instruction),
    INSN_ENTRY(0xf5, 1, 16, IMP_push_pair),
    INSN_blank(0xf6, 1, 8, IMP_or_0xf6),
    INSN_ENTRY(0xf7, 1, 16, IMP_rst_vec),
    INSN_blank(0xf8, 1, 12, IMP_ld_0xf8),
    INSN_blank(0xf9, 1, 8, IMP_ld_0xf9),
    INSN_ENTRY(0xfa, 1, 16, IMP_insn_ld_absolute),
    INSN_ENTRY(0xfb, 1, 4, IMP_edi),
    INSN_ENTRY(0xfc, 1, 0, IMP_undefined_instruction),
    INSN_ENTRY(0xfd, 1, 0, IMP_undefined_instruction),
    INSN_blank(0xfe, 1, 8, IMP_cp_0xfe),
    INSN_ENTRY(0xff, 1, 16, IMP_rst_vec),
};

#endif