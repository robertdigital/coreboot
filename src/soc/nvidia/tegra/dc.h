/*
 *  Copyright 2013 Google Inc.
 *  (C) Copyright 2010
 *  NVIDIA Corporation <www.nvidia.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __SOC_NVIDIA_TEGRA_DC_H
#define __SOC_NVIDIA_TEGRA_DC_H

/* Register definitions for the Tegra display controller */

/* CMD register 0x000 ~ 0x43 */
struct dc_cmd_reg {
	/* Address 0x000 ~ 0x002 */
	u32 gen_incr_syncpt;		/* _CMD_GENERAL_INCR_SYNCPT_0 */
	u32 gen_incr_syncpt_ctrl;	/* _CMD_GENERAL_INCR_SYNCPT_CNTRL_0 */
	u32 gen_incr_syncpt_err;	/* _CMD_GENERAL_INCR_SYNCPT_ERROR_0 */

	u32 reserved0[5];		/* reserved_0[5] */

	/* Address 0x008 ~ 0x00a */
	u32 win_a_incr_syncpt;		/* _CMD_WIN_A_INCR_SYNCPT_0 */
	u32 win_a_incr_syncpt_ctrl;	/* _CMD_WIN_A_INCR_SYNCPT_CNTRL_0 */
	u32 win_a_incr_syncpt_err;	/* _CMD_WIN_A_INCR_SYNCPT_ERROR_0 */

	u32 reserved1[5];		/* reserved_1[5] */

	/* Address 0x010 ~ 0x012 */
	u32 win_b_incr_syncpt;		/* _CMD_WIN_B_INCR_SYNCPT_0 */
	u32 win_b_incr_syncpt_ctrl;	/* _CMD_WIN_B_INCR_SYNCPT_CNTRL_0 */
	u32 win_b_incr_syncpt_err;	/* _CMD_WIN_B_INCR_SYNCPT_ERROR_0 */

	u32 reserved2[5];		/* reserved_2[5] */

	/* Address 0x018 ~ 0x01a */
	u32 win_c_incr_syncpt;		/* _CMD_WIN_C_INCR_SYNCPT_0 */
	u32 win_c_incr_syncpt_ctrl;	/* _CMD_WIN_C_INCR_SYNCPT_CNTRL_0 */
	u32 win_c_incr_syncpt_err;	/* _CMD_WIN_C_INCR_SYNCPT_ERROR_0 */

	u32 reserved3[13];		/* reserved_3[13] */

	/* Address 0x028 */
	u32 cont_syncpt_vsync;		/* _CMD_CONT_SYNCPT_VSYNC_0 */

	u32 reserved4[7];		/* reserved_4[7] */

	/* Address 0x030 ~ 0x033 */
	u32 ctxsw;			/* _CMD_CTXSW_0 */
	u32 disp_cmd_opt0;		/* _CMD_DISPLAY_COMMAND_OPTION0_0 */
	u32 disp_cmd;			/* _CMD_DISPLAY_COMMAND_0 */
	u32 sig_raise;			/* _CMD_SIGNAL_RAISE_0 */

	u32 reserved5[2];		/* reserved_0[2] */

	/* Address 0x036 ~ 0x03e */
	u32 disp_pow_ctrl;		/* _CMD_DISPLAY_POWER_CONTROL_0 */
	u32 int_stat;			/* _CMD_INT_STATUS_0 */
	u32 int_mask;			/* _CMD_INT_MASK_0 */
	u32 int_enb;			/* _CMD_INT_ENABLE_0 */
	u32 int_type;			/* _CMD_INT_TYPE_0 */
	u32 int_polarity;		/* _CMD_INT_POLARITY_0 */
	u32 sig_raise1;		/* _CMD_SIGNAL_RAISE1_0 */
	u32 sig_raise2;		/* _CMD_SIGNAL_RAISE2_0 */
	u32 sig_raise3;		/* _CMD_SIGNAL_RAISE3_0 */

	u32 reserved6;			/* reserved_6 */

	/* Address 0x040 ~ 0x043 */
	u32 state_access;		/* _CMD_STATE_ACCESS_0 */
	u32 state_ctrl;		/* _CMD_STATE_CONTROL_0 */
	u32 disp_win_header;		/* _CMD_DISPLAY_WINDOW_HEADER_0 */
	u32 reg_act_ctrl;		/* _CMD_REG_ACT_CONTROL_0 */
};

enum {
	PIN_REG_COUNT		= 4,
	PIN_OUTPUT_SEL_COUNT	= 7,
};

/* COM register 0x300 ~ 0x329 */
struct dc_com_reg {
	/* Address 0x300 ~ 0x301 */
	u32 crc_ctrl;			/* _COM_CRC_CONTROL_0 */
	u32 crc_checksum;		/* _COM_CRC_CHECKSUM_0 */

	/* _COM_PIN_OUTPUT_ENABLE0/1/2/3_0: Address 0x302 ~ 0x305 */
	u32 pin_output_enb[PIN_REG_COUNT];

	/* _COM_PIN_OUTPUT_POLARITY0/1/2/3_0: Address 0x306 ~ 0x309 */
	u32 pin_output_polarity[PIN_REG_COUNT];

	/* _COM_PIN_OUTPUT_DATA0/1/2/3_0: Address 0x30a ~ 0x30d */
	u32 pin_output_data[PIN_REG_COUNT];

	/* _COM_PIN_INPUT_ENABLE0_0: Address 0x30e ~ 0x311 */
	u32 pin_input_enb[PIN_REG_COUNT];

	/* Address 0x312 ~ 0x313 */
	u32 pin_input_data0;		/* _COM_PIN_INPUT_DATA0_0 */
	u32 pin_input_data1;		/* _COM_PIN_INPUT_DATA1_0 */

	/* _COM_PIN_OUTPUT_SELECT0/1/2/3/4/5/6_0: Address 0x314 ~ 0x31a */
	u32 pin_output_sel[PIN_OUTPUT_SEL_COUNT];

	/* Address 0x31b ~ 0x329 */
	u32 pin_misc_ctrl;		/* _COM_PIN_MISC_CONTROL_0 */
	u32 pm0_ctrl;			/* _COM_PM0_CONTROL_0 */
	u32 pm0_duty_cycle;		/* _COM_PM0_DUTY_CYCLE_0 */
	u32 pm1_ctrl;			/* _COM_PM1_CONTROL_0 */
	u32 pm1_duty_cycle;		/* _COM_PM1_DUTY_CYCLE_0 */
	u32 spi_ctrl;			/* _COM_SPI_CONTROL_0 */
	u32 spi_start_byte;		/* _COM_SPI_START_BYTE_0 */
	u32 hspi_wr_data_ab;		/* _COM_HSPI_WRITE_DATA_AB_0 */
	u32 hspi_wr_data_cd;		/* _COM_HSPI_WRITE_DATA_CD */
	u32 hspi_cs_dc;		/* _COM_HSPI_CS_DC_0 */
	u32 scratch_reg_a;		/* _COM_SCRATCH_REGISTER_A_0 */
	u32 scratch_reg_b;		/* _COM_SCRATCH_REGISTER_B_0 */
	u32 gpio_ctrl;			/* _COM_GPIO_CTRL_0 */
	u32 gpio_debounce_cnt;		/* _COM_GPIO_DEBOUNCE_COUNTER_0 */
	u32 crc_checksum_latched;	/* _COM_CRC_CHECKSUM_LATCHED_0 */
};

enum dc_disp_h_pulse_pos {
	H_PULSE0_POSITION_A,
	H_PULSE0_POSITION_B,
	H_PULSE0_POSITION_C,
	H_PULSE0_POSITION_D,
	H_PULSE0_POSITION_COUNT,
};

struct _disp_h_pulse {
	/* _DISP_H_PULSE0/1/2_CONTROL_0 */
	u32 h_pulse_ctrl;
	/* _DISP_H_PULSE0/1/2_POSITION_A/B/C/D_0 */
	u32 h_pulse_pos[H_PULSE0_POSITION_COUNT];
};

enum dc_disp_v_pulse_pos {
	V_PULSE0_POSITION_A,
	V_PULSE0_POSITION_B,
	V_PULSE0_POSITION_C,
	V_PULSE0_POSITION_COUNT,
};

struct _disp_v_pulse0 {
	/* _DISP_H_PULSE0/1_CONTROL_0 */
	u32 v_pulse_ctrl;
	/* _DISP_H_PULSE0/1_POSITION_A/B/C_0 */
	u32 v_pulse_pos[V_PULSE0_POSITION_COUNT];
};

struct _disp_v_pulse2 {
	/* _DISP_H_PULSE2/3_CONTROL_0 */
	u32 v_pulse_ctrl;
	/* _DISP_H_PULSE2/3_POSITION_A_0 */
	u32 v_pulse_pos_a;
};

enum dc_disp_h_pulse_reg {
	H_PULSE0,
	H_PULSE1,
	H_PULSE2,
	H_PULSE_COUNT,
};

enum dc_disp_pp_select {
	PP_SELECT_A,
	PP_SELECT_B,
	PP_SELECT_C,
	PP_SELECT_D,
	PP_SELECT_COUNT,
};

/* DISP register 0x400 ~ 0x4c1 */
struct dc_disp_reg {
	/* Address 0x400 ~ 0x40a */
	u32 disp_signal_opt0;		/* _DISP_DISP_SIGNAL_OPTIONS0_0 */
	u32 disp_signal_opt1;		/* _DISP_DISP_SIGNAL_OPTIONS1_0 */
	u32 disp_win_opt;		/* _DISP_DISP_WIN_OPTIONS_0 */
	u32 mem_high_pri;		/* _DISP_MEM_HIGH_PRIORITY_0 */
	u32 mem_high_pri_timer;	/* _DISP_MEM_HIGH_PRIORITY_TIMER_0 */
	u32 disp_timing_opt;		/* _DISP_DISP_TIMING_OPTIONS_0 */
	u32 ref_to_sync;		/* _DISP_REF_TO_SYNC_0 */
	u32 sync_width;		/* _DISP_SYNC_WIDTH_0 */
	u32 back_porch;		/* _DISP_BACK_PORCH_0 */
	u32 disp_active;		/* _DISP_DISP_ACTIVE_0 */
	u32 front_porch;		/* _DISP_FRONT_PORCH_0 */

	/* Address 0x40b ~ 0x419: _DISP_H_PULSE0/1/2_  */
	struct _disp_h_pulse h_pulse[H_PULSE_COUNT];

	/* Address 0x41a ~ 0x421 */
	struct _disp_v_pulse0 v_pulse0;	/* _DISP_V_PULSE0_ */
	struct _disp_v_pulse0 v_pulse1;	/* _DISP_V_PULSE1_ */

	/* Address 0x422 ~ 0x425 */
	struct _disp_v_pulse2 v_pulse3;	/* _DISP_V_PULSE2_ */
	struct _disp_v_pulse2 v_pulse4;	/* _DISP_V_PULSE3_ */

	/* Address 0x426 ~ 0x429 */
	u32 m0_ctrl;			/* _DISP_M0_CONTROL_0 */
	u32 m1_ctrl;			/* _DISP_M1_CONTROL_0 */
	u32 di_ctrl;			/* _DISP_DI_CONTROL_0 */
	u32 pp_ctrl;			/* _DISP_PP_CONTROL_0 */

	/* Address 0x42a ~ 0x42d: _DISP_PP_SELECT_A/B/C/D_0 */
	u32 pp_select[PP_SELECT_COUNT];

	/* Address 0x42e ~ 0x435 */
	u32 disp_clk_ctrl;		/* _DISP_DISP_CLOCK_CONTROL_0 */
	u32 disp_interface_ctrl;	/* _DISP_DISP_INTERFACE_CONTROL_0 */
	u32 disp_color_ctrl;		/* _DISP_DISP_COLOR_CONTROL_0 */
	u32 shift_clk_opt;		/* _DISP_SHIFT_CLOCK_OPTIONS_0 */
	u32 data_enable_opt;		/* _DISP_DATA_ENABLE_OPTIONS_0 */
	u32 serial_interface_opt;	/* _DISP_SERIAL_INTERFACE_OPTIONS_0 */
	u32 lcd_spi_opt;		/* _DISP_LCD_SPI_OPTIONS_0 */
	u32 border_color;		/* _DISP_BORDER_COLOR_0 */

	/* Address 0x436 ~ 0x439 */
	u32 color_key0_lower;		/* _DISP_COLOR_KEY0_LOWER_0 */
	u32 color_key0_upper;		/* _DISP_COLOR_KEY0_UPPER_0 */
	u32 color_key1_lower;		/* _DISP_COLOR_KEY1_LOWER_0 */
	u32 color_key1_upper;		/* _DISP_COLOR_KEY1_UPPER_0 */

	u32 reserved0[2];		/* reserved_0[2] */

	/* Address 0x43c ~ 0x442 */
	u32 cursor_foreground;		/* _DISP_CURSOR_FOREGROUND_0 */
	u32 cursor_background;		/* _DISP_CURSOR_BACKGROUND_0 */
	u32 cursor_start_addr;		/* _DISP_CURSOR_START_ADDR_0 */
	u32 cursor_start_addr_ns;	/* _DISP_CURSOR_START_ADDR_NS_0 */
	u32 cursor_pos;		/* _DISP_CURSOR_POSITION_0 */
	u32 cursor_pos_ns;		/* _DISP_CURSOR_POSITION_NS_0 */
	u32 seq_ctrl;			/* _DISP_INIT_SEQ_CONTROL_0 */

	/* Address 0x442 ~ 0x446 */
	u32 spi_init_seq_data_a;	/* _DISP_SPI_INIT_SEQ_DATA_A_0 */
	u32 spi_init_seq_data_b;	/* _DISP_SPI_INIT_SEQ_DATA_B_0 */
	u32 spi_init_seq_data_c;	/* _DISP_SPI_INIT_SEQ_DATA_C_0 */
	u32 spi_init_seq_data_d;	/* _DISP_SPI_INIT_SEQ_DATA_D_0 */

	u32 reserved1[0x39];		/* reserved1[0x39], */

	/* Address 0x480 ~ 0x484 */
	u32 dc_mccif_fifoctrl;		/* _DISP_DC_MCCIF_FIFOCTRL_0 */
	u32 mccif_disp0a_hyst;		/* _DISP_MCCIF_DISPLAY0A_HYST_0 */
	u32 mccif_disp0b_hyst;		/* _DISP_MCCIF_DISPLAY0B_HYST_0 */
	u32 mccif_disp0c_hyst;		/* _DISP_MCCIF_DISPLAY0C_HYST_0 */
	u32 mccif_disp1b_hyst;		/* _DISP_MCCIF_DISPLAY1B_HYST_0 */

	u32 reserved2[0x3b];		/* reserved2[0x3b] */

	/* Address 0x4c0 ~ 0x4c1 */
	u32 dac_crt_ctrl;		/* _DISP_DAC_CRT_CTRL_0 */
	u32 disp_misc_ctrl;		/* _DISP_DISP_MISC_CONTROL_0 */
};

enum dc_winc_filter_p {
	WINC_FILTER_COUNT	= 0x10,
};

/* Window A/B/C register 0x500 ~ 0x628 */
struct dc_winc_reg {

	/* Address 0x500 */
	u32 color_palette;		/* _WINC_COLOR_PALETTE_0 */

	u32 reserved0[0xff];		/* reserved_0[0xff] */

	/* Address 0x600 */
	u32 palette_color_ext;		/* _WINC_PALETTE_COLOR_EXT_0 */

	/* _WINC_H_FILTER_P00~0F_0 */
	/* Address 0x601 ~ 0x610 */
	u32 h_filter_p[WINC_FILTER_COUNT];

	/* Address 0x611 ~ 0x618 */
	u32 csc_yof;			/* _WINC_CSC_YOF_0 */
	u32 csc_kyrgb;			/* _WINC_CSC_KYRGB_0 */
	u32 csc_kur;			/* _WINC_CSC_KUR_0 */
	u32 csc_kvr;			/* _WINC_CSC_KVR_0 */
	u32 csc_kug;			/* _WINC_CSC_KUG_0 */
	u32 csc_kvg;			/* _WINC_CSC_KVG_0 */
	u32 csc_kub;			/* _WINC_CSC_KUB_0 */
	u32 csc_kvb;			/* _WINC_CSC_KVB_0 */

	/* Address 0x619 ~ 0x628: _WINC_V_FILTER_P00~0F_0 */
	u32 v_filter_p[WINC_FILTER_COUNT];
};

/* WIN A/B/C Register 0x700 ~ 0x714*/
struct dc_win_reg {
	/* Address 0x700 ~ 0x714 */
	u32 win_opt;			/* _WIN_WIN_OPTIONS_0 */
	u32 byte_swap;			/* _WIN_BYTE_SWAP_0 */
	u32 buffer_ctrl;		/* _WIN_BUFFER_CONTROL_0 */
	u32 color_depth;		/* _WIN_COLOR_DEPTH_0 */
	u32 pos;			/* _WIN_POSITION_0 */
	u32 size;			/* _WIN_SIZE_0 */
	u32 prescaled_size;		/* _WIN_PRESCALED_SIZE_0 */
	u32 h_initial_dda;		/* _WIN_H_INITIAL_DDA_0 */
	u32 v_initial_dda;		/* _WIN_V_INITIAL_DDA_0 */
	u32 dda_increment;		/* _WIN_DDA_INCREMENT_0 */
	u32 line_stride;		/* _WIN_LINE_STRIDE_0 */
	u32 buf_stride;		/* _WIN_BUF_STRIDE_0 */
	u32 uv_buf_stride;		/* _WIN_UV_BUF_STRIDE_0 */
	u32 buffer_addr_mode;		/* _WIN_BUFFER_ADDR_MODE_0 */
	u32 dv_ctrl;			/* _WIN_DV_CONTROL_0 */
	u32 blend_nokey;		/* _WIN_BLEND_NOKEY_0 */
	u32 blend_1win;		/* _WIN_BLEND_1WIN_0 */
	u32 blend_2win_x;		/* _WIN_BLEND_2WIN_X_0 */
	u32 blend_2win_y;		/* _WIN_BLEND_2WIN_Y_0 */
	u32 blend_3win_xy;		/* _WIN_BLEND_3WIN_XY_0 */
	u32 hp_fetch_ctrl;		/* _WIN_HP_FETCH_CONTROL_0 */
};

/* WINBUF A/B/C Register 0x800 ~ 0x80a */
struct dc_winbuf_reg {
	/* Address 0x800 ~ 0x80a */
	u32 start_addr;		/* _WINBUF_START_ADDR_0 */
	u32 start_addr_ns;		/* _WINBUF_START_ADDR_NS_0 */
	u32 start_addr_u;		/* _WINBUF_START_ADDR_U_0 */
	u32 start_addr_u_ns;		/* _WINBUF_START_ADDR_U_NS_0 */
	u32 start_addr_v;		/* _WINBUF_START_ADDR_V_0 */
	u32 start_addr_v_ns;		/* _WINBUF_START_ADDR_V_NS_0 */
	u32 addr_h_offset;		/* _WINBUF_ADDR_H_OFFSET_0 */
	u32 addr_h_offset_ns;		/* _WINBUF_ADDR_H_OFFSET_NS_0 */
	u32 addr_v_offset;		/* _WINBUF_ADDR_V_OFFSET_0 */
	u32 addr_v_offset_ns;		/* _WINBUF_ADDR_V_OFFSET_NS_0 */
	u32 uflow_status;		/* _WINBUF_UFLOW_STATUS_0 */
};

/* Display Controller (DC_) regs */
struct display_controller {
	struct dc_cmd_reg cmd;		/* CMD register 0x000 ~ 0x43 */
	u32 reserved0[0x2bc];

	struct dc_com_reg com;		/* COM register 0x300 ~ 0x329 */
	u32 reserved1[0xd6];

	struct dc_disp_reg disp;	/* DISP register 0x400 ~ 0x4c1 */
	u32 reserved2[0x3e];

	struct dc_winc_reg winc;	/* Window A/B/C 0x500 ~ 0x628 */
	u32 reserved3[0xd7];

	struct dc_win_reg win;		/* WIN A/B/C 0x700 ~ 0x714*/
	u32 reserved4[0xeb];

	struct dc_winbuf_reg winbuf;	/* WINBUF A/B/C 0x800 ~ 0x80a */
};

#define BIT(pos)	(1U << pos)

/* DC_CMD_DISPLAY_COMMAND 0x032 */
#define CTRL_MODE_SHIFT		5
#define CTRL_MODE_MASK		(0x3 << CTRL_MODE_SHIFT)
enum {
	CTRL_MODE_STOP,
	CTRL_MODE_C_DISPLAY,
	CTRL_MODE_NC_DISPLAY,
};

/* _WIN_COLOR_DEPTH_0 */
enum win_color_depth_id {
	COLOR_DEPTH_P1,
	COLOR_DEPTH_P2,
	COLOR_DEPTH_P4,
	COLOR_DEPTH_P8,
	COLOR_DEPTH_B4G4R4A4,
	COLOR_DEPTH_B5G5R5A,
	COLOR_DEPTH_B5G6R5,
	COLOR_DEPTH_AB5G5R5,
	COLOR_DEPTH_B8G8R8A8 = 12,
	COLOR_DEPTH_R8G8B8A8,
	COLOR_DEPTH_B6x2G6x2R6x2A8,
	COLOR_DEPTH_R6x2G6x2B6x2A8,
	COLOR_DEPTH_YCbCr422,
	COLOR_DEPTH_YUV422,
	COLOR_DEPTH_YCbCr420P,
	COLOR_DEPTH_YUV420P,
	COLOR_DEPTH_YCbCr422P,
	COLOR_DEPTH_YUV422P,
	COLOR_DEPTH_YCbCr422R,
	COLOR_DEPTH_YUV422R,
	COLOR_DEPTH_YCbCr422RA,
	COLOR_DEPTH_YUV422RA,
};

/* DC_CMD_DISPLAY_POWER_CONTROL 0x036 */
#define PW0_ENABLE		BIT(0)
#define PW1_ENABLE		BIT(2)
#define PW2_ENABLE		BIT(4)
#define PW3_ENABLE		BIT(6)
#define PW4_ENABLE		BIT(8)
#define PM0_ENABLE		BIT(16)
#define PM1_ENABLE		BIT(18)
#define SPI_ENABLE		BIT(24)
#define HSPI_ENABLE		BIT(25)

/* DC_CMD_STATE_CONTROL 0x041 */
#define GENERAL_ACT_REQ		BIT(0)
#define WIN_A_ACT_REQ		BIT(1)
#define WIN_B_ACT_REQ		BIT(2)
#define WIN_C_ACT_REQ		BIT(3)
#define GENERAL_UPDATE		BIT(8)
#define WIN_A_UPDATE		BIT(9)
#define WIN_B_UPDATE		BIT(10)
#define WIN_C_UPDATE		BIT(11)

/* DC_CMD_DISPLAY_WINDOW_HEADER 0x042 */
#define WINDOW_A_SELECT		BIT(4)
#define WINDOW_B_SELECT		BIT(5)
#define WINDOW_C_SELECT		BIT(6)

/* DC_DISP_DISP_CLOCK_CONTROL 0x42e */
#define SHIFT_CLK_DIVIDER_SHIFT	0
#define SHIFT_CLK_DIVIDER_MASK	(0xff << SHIFT_CLK_DIVIDER_SHIFT)
#define	PIXEL_CLK_DIVIDER_SHIFT	8
#define	PIXEL_CLK_DIVIDER_MSK	(0xf << PIXEL_CLK_DIVIDER_SHIFT)
enum {
	PIXEL_CLK_DIVIDER_PCD1,
	PIXEL_CLK_DIVIDER_PCD1H,
	PIXEL_CLK_DIVIDER_PCD2,
	PIXEL_CLK_DIVIDER_PCD3,
	PIXEL_CLK_DIVIDER_PCD4,
	PIXEL_CLK_DIVIDER_PCD6,
	PIXEL_CLK_DIVIDER_PCD8,
	PIXEL_CLK_DIVIDER_PCD9,
	PIXEL_CLK_DIVIDER_PCD12,
	PIXEL_CLK_DIVIDER_PCD16,
	PIXEL_CLK_DIVIDER_PCD18,
	PIXEL_CLK_DIVIDER_PCD24,
	PIXEL_CLK_DIVIDER_PCD13,
};

/* DC_DISP_DISP_INTERFACE_CONTROL 0x42f */
#define DATA_FORMAT_SHIFT	0
#define DATA_FORMAT_MASK	(0xf << DATA_FORMAT_SHIFT)
enum {
	DATA_FORMAT_DF1P1C,
	DATA_FORMAT_DF1P2C24B,
	DATA_FORMAT_DF1P2C18B,
	DATA_FORMAT_DF1P2C16B,
	DATA_FORMAT_DF2S,
	DATA_FORMAT_DF3S,
	DATA_FORMAT_DFSPI,
	DATA_FORMAT_DF1P3C24B,
	DATA_FORMAT_DF1P3C18B,
};
#define DATA_ALIGNMENT_SHIFT	8
enum {
	DATA_ALIGNMENT_MSB,
	DATA_ALIGNMENT_LSB,
};
#define DATA_ORDER_SHIFT	9
enum {
	DATA_ORDER_RED_BLUE,
	DATA_ORDER_BLUE_RED,
};

/* DC_DISP_DATA_ENABLE_OPTIONS 0x432 */
#define DE_SELECT_SHIFT		0
#define DE_SELECT_MASK		(0x3 << DE_SELECT_SHIFT)
#define DE_SELECT_ACTIVE_BLANK	0x0
#define DE_SELECT_ACTIVE	0x1
#define DE_SELECT_ACTIVE_IS	0x2
#define DE_CONTROL_SHIFT	2
#define DE_CONTROL_MASK		(0x7 << DE_CONTROL_SHIFT)
enum {
	DE_CONTROL_ONECLK,
	DE_CONTROL_NORMAL,
	DE_CONTROL_EARLY_EXT,
	DE_CONTROL_EARLY,
	DE_CONTROL_ACTIVE_BLANK,
};

/* DC_WIN_WIN_OPTIONS 0x700 */
#define H_DIRECTION		BIT(0)
enum {
	H_DIRECTION_INCREMENT,
	H_DIRECTION_DECREMENT,
};
#define V_DIRECTION		BIT(2)
enum {
	V_DIRECTION_INCREMENT,
	V_DIRECTION_DECREMENT,
};
#define COLOR_EXPAND		BIT(6)
#define CP_ENABLE		BIT(16)
#define DV_ENABLE		BIT(20)
#define WIN_ENABLE		BIT(30)

/* DC_WIN_BYTE_SWAP 0x701 */
#define BYTE_SWAP_SHIFT		0
#define BYTE_SWAP_MASK		(3 << BYTE_SWAP_SHIFT)
enum {
	BYTE_SWAP_NOSWAP,
	BYTE_SWAP_SWAP2,
	BYTE_SWAP_SWAP4,
	BYTE_SWAP_SWAP4HW
};

/* DC_WIN_POSITION 0x704 */
#define H_POSITION_SHIFT	0
#define H_POSITION_MASK		(0x1FFF << H_POSITION_SHIFT)
#define V_POSITION_SHIFT	16
#define V_POSITION_MASK		(0x1FFF << V_POSITION_SHIFT)

/* DC_WIN_SIZE 0x705 */
#define H_SIZE_SHIFT		0
#define H_SIZE_MASK		(0x1FFF << H_SIZE_SHIFT)
#define V_SIZE_SHIFT		16
#define V_SIZE_MASK		(0x1FFF << V_SIZE_SHIFT)

/* DC_WIN_PRESCALED_SIZE 0x706 */
#define H_PRESCALED_SIZE_SHIFT	0
#define H_PRESCALED_SIZE_MASK	(0x7FFF << H_PRESCALED_SIZE)
#define V_PRESCALED_SIZE_SHIFT	16
#define V_PRESCALED_SIZE_MASK	(0x1FFF << V_PRESCALED_SIZE)

/* DC_WIN_DDA_INCREMENT 0x709 */
#define H_DDA_INC_SHIFT		0
#define H_DDA_INC_MASK		(0xFFFF << H_DDA_INC_SHIFT)
#define V_DDA_INC_SHIFT		16
#define V_DDA_INC_MASK		(0xFFFF << V_DDA_INC_SHIFT)

/* This holds information about a window which can be displayed */
/* TODO: do we really need this for basic setup? Not sure yet. */
struct disp_ctl_win {
	enum win_color_depth_id fmt;	/* Color depth/format */
	u32	bpp;		/* Bits per pixel */
	u32	phys_addr;	/* Physical address in memory */
	u32	x;		/* Horizontal address offset (bytes) */
	u32	y;		/* Veritical address offset (bytes) */
	u32	w;		/* Width of source window */
	u32	h;		/* Height of source window */
	u32	stride;		/* Number of bytes per line */
	u32	out_x;		/* Left edge of output window (col) */
	u32	out_y;		/* Top edge of output window (row) */
	u32	out_w;		/* Width of output window in pixels */
	u32	out_h;		/* Height of output window in pixels */
};

void display_startup(device_t dev);
void dp_bringup(u32 winb_addr);
#endif /* __SOC_NVIDIA_TEGRA_DC_H */
