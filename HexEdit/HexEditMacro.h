// HexEditMacro.h : header file for keystroke macro structure
//
// Copyright (c) 2004-2011 by Andrew W. Phillips.
//
// No restrictions are placed on the noncommercial use of this code,
// as long as this text (from the above copyright notice to the
// disclaimer below) is preserved.
//
// This code may be redistributed as long as it remains unmodified
// and is not sold for profit without the author's written consent.
//
// This code, or any part of it, may not be used in any software that
// is sold for profit, without the author's written consent.
//
// DISCLAIMER: This file is provided "as is" with no expressed or
// implied warranty. The author accepts no liability for any damage
// or loss of business that this product may cause.
//

enum km_type
{
	km_unknown = 0,             // Help detect errors
	km_new,                     // Create new file (64 bit int stores various fill options) - also see km_new_str
	km_open,                    // Open existing file
	km_print_setup,             // Print setup
	km_exit,                    // Exit program

	km_find_text,               // Set current find text
	km_toolbar,                 // Toggle toolbar
	km_replace_text,            // Set current replace text
	km_bar,                     // Toggle other bar (inc. status bar)

	km_prop,                    // Properties dialog
	km_prop_file,               // Change to the file page
	km_prop_char,               // Change to the char page
	km_prop_dec,                // Change to the decimal values page
	km_prop_float,              // Change to the floating point page
	km_prop_ibmfp,              // Change to the IBM floating point page
	km_prop_checksum,           // Change to the checksum page (not implemented)
	km_prop_close,              // Close properties dialog
	km_calc_dlg,                // Invoke the goto/calculator dialog (see also km_goto) -1 = hide, 0 = show, 1=OnCalcSel
	km_calc_close,              // NO LONGER USED (see km_calc_dlg) but may still be in old macro files
	km_help,                    // F1 pressed (help)
	km_topics,                  // Help Topics
	km_tips,                    // Tip of the day
	km_about,                   // About dialog (not implemented)

	km_focus,                   // Switch view (mouse click or windows menu)
	km_mainsys,                 // System command (mainframe control menu)
	km_childsys,                // System command (child frame control menu)

	// Commands added in 2.0
	km_encrypt_alg,             // Set encryption algorithm
	km_encrypt_password,        // Set/clear encryption password

	// Commands added in 2.1
	km_prop_date,               // Change to the date page
	km_prop_crc,                // CRC page (not implemented) - part of checksum page?
	km_prop_graph,              // Stats graph
	km_prop_stats,              // statistics page: digest (crypto checksum) etc

	// Commands added in 2.2
	km_macro_message,           // display message during playback
	km_macro_play,              // nested call to (file) macro

	km_bookmarks_goto,          // Goto a named bookmark

	// 3.0
	km_new_str,                 // Always follows km_new and stores fill string (text, hex, range etc dep. on options)

	km_last_global, // = 35?    // leave as last value before km_calc

	//---------------------------------------------------------
	// The following (50-99) are generated by the calculator.  The gap was left
	// so that new commands can be added later and not intermixed,
	// without changing any existing enum values.  This means existing
	// macro files (when we have them) won't be invalidated.
	// There is also a 2nd group of calculator operations (km_go etc)
	// that require an active view (hence they are past km_view).
	km_calc = 50,               // First calc value

	// Calculator misc operations
	km_result = 50,             // Used to signal that the value is not to be stored, which
								// happens if the value is the result of a binary or unary
								// operation or it was entered before recording started.
								// Note: this value is never actually stored in a macro.
	km_user,                    // Replaced by km_user_str in 4.X to allow for integers bigger than 64 bits
	km_clear,                   // Clear calculator operands and operator
	km_clear_entry,             // Clear current operand
	km_equals,                  // Evaluate result (equals key)

	// Change modes
	km_change_bits,             // Change the number of bits displayed (and used for calcs)
	km_change_base,             // Change the radix for display (also affects results since decimal means signed operations)
	km_endian,                  // No longer generated - replaced by km_big_endian

	// Operations (the actual op number is stored in vv)
	km_binop,                   // Binary operation
	km_unaryop,                 // Unary operation

	// Calculator memory operations (store etc)
	km_memget,                  // Get current value of calculator memory
	km_memstore,                // Store into calc memory
	km_memclear,                // Clear calc memory
	km_memadd,                  // Add to calc memory
	km_memsubtract,             // Subtract from calc memory

	km_expression,              // User entered an expression (cf km_user) - string stored in *pss
	km_user_str,                // Replaces km_user - stores the integer in a string (pss) rather than 64 bit int (v64)
	km_change_signed,           // Toggled signed_ in calculator

	km_last_calc, // = 68?      // leave as last value before km_view

	//-------------------------------------------------
	km_view = 100,              // All past this point require a view
	km_close,                   // File Close
	km_save,                    // File Save
	km_saveas,                  // File Save As
	km_print,                   // Print - bring up print dlg
	km_preview,                 // Print preview

	km_undo,                    // Undo
	km_redo,                    // Redo (not implemented)
	km_cut,                     // Cut
	km_copy,                    // Copy
	km_paste,                   // Paste
	km_del,                     // Delete character or selection
	km_copy_hex,                // Copy as hex text
	km_copy_decimal,            // Copy as decimal text (not implemented)
	km_copy_binary,             // Copy as binary text (not implemented)
	km_copy_cchar,              // Copy as C source (string, chars, ints, etc)

	km_copy_cstring,            // No longer to be used (may be reused)
	km_copy_cword,              // No longer to be used (may be reused)
	km_copy_cdword,             // No longer to be used (may be reused)
	km_copy_cqword,             // No longer to be used (may be reused)
	km_copy_cfloat,             // No longer to be used (may be reused)
	km_copy_cdouble,            // No longer to be used (may be reused)

	km_paste_ascii,             // Paste as ASCII
	km_paste_unicode,           // Paste as Unicode
	km_paste_ebcdic,            // Paste as EBCDIC
	km_sel_all,                 // Select whole file

	km_write_file,              // Write selection to file
	km_append_file,             // Append selection to a file
	km_read_file,               // Read file & leave selected
	km_find_dlg,                // Invoke the Find dialog and display a certain page
	km_find_close,              // NO LONGER USED but may still exist in old macro files
	km_find_back,               // Repeat find backwards (SF3)
	km_find_forw,               // Repeat find forwards (F3)
	km_find_sel,                // Find current selection (^F3)

	km_goto,                    // Invoke calculator in goto mode
	km_ro_rw,                   // Toggle RO/RW
	km_ovr_ins,                 // Toggle OVR/INS
	km_mark_pos,                // Mark position
	km_goto_mark,               // Goto mark
	km_extendto_mark,           // Extend selection to mark
	km_swap_mark,               // Swap caret with mark
	km_highlight,               // Highlighter 0=clear, 1=highlight, 2=prev, 3=next, 4=hide

	km_aerial,                  // Show aerial view (not implemented)
	km_autofit,                 // Toggle autofit
	km_font,                    // Font dialog
	km_inc_font,                // Increase font
	km_dec_font,                // Decrease font
	km_addr,                    // Toggle hex/decimal addresses
	km_char_area,               // Toggle char area
	km_ebcdic,                  // Toggle ASCII/EBCDIC
	km_control,                 // Change display of control chars
	km_control2,                // Toggle display of control chars (last used in 2.1)
	km_graphic,                 // Toggle display of graphic chars
	km_oem,                     // Toggle between ANSI/OEM graphic chars

	km_rowsize,                 // Change number of columns -1 = dec, -2 = inc, else new rowsize
	km_group_by,                // Change column grouping
	km_offset,                  // Change column of first byte

	km_win_new,                 // Open new window on active file
	km_win_next,                // Move to next non-minimized window
	km_win_cmd,                 // Handles window menu commands: cascade, tile, arrange

	km_redraw,                  // Redraw and scroll to centre
	km_scroll_up,               // Scroll up
	km_scroll_down,             // Scroll down
	km_swap_areas,              // Swap between hex and character areas
	km_start_line,              // Change offset so that cursor is at start of line

	km_key,                     // Key (from OnKeyDown event)
	km_char,                    // Normal char + control chars
	km_mouse,                   // Mouse click/drag
	km_shift_mouse,             // Mouse click/drag shift key down
	km_hscroll,                 // Scroll window horizontally
	km_vscroll,                 // Scroll window vertically

	km_address_tool,            // Hex/decimal address tool used (NO LONGER USED)

	// The following are tools.  This is likely to be added to extensively.
	km_compare,                 // Compare windows
	km_inc8,                    // Increment byte
	km_inc16,                   // Increment word
	km_inc32,                   // Increment double word
	km_inc64,                   // Increment quad word
	km_dec8,                    // Decrement byte
	km_dec16,                   // Decrement word
	km_dec32,                   // Decrement double word
	km_dec64,                   // Decrement quad word
	km_flip16,                  // Swap bytes of word
	km_flip32,                  // Swap bytes of double word
	km_flip64,                  // Swap bytes of quad word

	km_rs_forw,                 // Encom RS (no longer used)
	km_rs_back,                 // Encom RS (no longer used)

	// Calculator file operations
	km_go,                      // Move caret and move focus from calc to edit view
	km_markstore,               // Set the mark using the current calc value
	km_markclear,               // Set mark to beginning of file
	km_markadd,                 // Add calc value to mark address
	km_marksubtract,            // Subtract cal value from mark address
	km_markatstore,             // Store calc value to file at the current mark position
	km_selstore,                // Move current caret position to current calc value
	km_selatstore,              // Store calc value to file at the current caret position
	km_selendstore,             // Set end of current selection (must be >= sel start && <= eof)
	km_sellenstore,             // Set length of selection (must be >= 0 && <= dist to EOF)

	// Where is a calculator value obtained from?
	// Note: km_user, km_user_str and km_expression also say where a value comes from but
	// as they do not require a view they appear in the 50-99 range (above).
	km_markget,                 // Get current address of mark
	km_markat,                  // Get value from file at mark
	km_bookmark,                // Not used
	km_bookmarkat,              // Not used
	km_selget,                  // Get current address of caret/start of selection
	km_selat,                   // Get current value from file at caret
	km_selend,                  // Get current address of end of selection
	km_sellen,                  // Get length of selection
	km_eofget,                  // Get length of file

	// Tools added for version 1.2
	km_invert,                  // Invert bits (NOT)
	km_neg8,                    // Negate (change sign) of byte
	km_neg16,                   // Negate (change sign) of word
	km_neg32,                   // Negate (change sign) of double word
	km_neg64,                   // Negate (change sign) of quad word

	// Commands added in 2.0
	km_sel_line,                // Select current line
	km_convert,                 // Do various conversions of the current selection (see enum convert_type)
	km_encrypt,                 // encrypt or decrypt

	// Commands added in 2.1
	km_append_same_file,        // Append selection to same file last written
	km_undo_changes,            // Undo changes
	km_hex_area,                // -1 = toggle, 0 = off, 1 = on
	km_display_reset,           // Reset display to the defaults

	// Commands added in 2.2
	km_area,
	km_charset,
	km_scheme,                  // Change colour scheme
	km_display_state,           // Change state of the display
//    km_export,                  // This is handled by km_write_file
	km_import_motorola,         // Import a Motorola S-record file
	km_import_intel,            // Import an Intel hex file
	km_import_text,             // Import a hex text file

	km_op_binary,               // Used for binary operations (other operand is current calculator value)
								// like binop_xor and others when added.

	km_op_unary,                // Replaces km_invert, km_neg/km_inc/km_dec/km_flip* and
								// also used for new unary operations when added.

	km_checksum,                // Checksums, CRCs, MD5 etc (see enum checksum_type)

	km_address_hex,             // Hex address tool used
	km_address_dec,             // Decimal address tool used

	// Commands added in 2.5
	km_bookmarks,               // (cf km_bookmark) 0 = clear, 2 = goto prev, 3 = goto next, 4 = toggle hide
								// 5 = show bookmarks dialog, 6 = hide bookmarks dialog, 7 = toggle unnamed bookmark
	km_bookmarks_add,           // Add a global bookmark (name provided)

	km_find_next,               // Start search based on current find options (= Find Next button)
	km_bookmark_all,            // Search for all occurrences and bookmark them (= Bookmark All button)
	km_replace,                 // Start find and replace (= Replace button)
	km_replace_all,             // Replace all based on current options (= Replace All button)

	km_dffd_sync,               // 255 = sync now, 2 = toggle auto sync

	// Commands added in 3.0
	km_track_changes,           // -1 = toggle
	km_big_endian,              // -1 = toggle, 0 = little-endian, 1 = big-endian

	km_insert,                  // Insert filled block stored value = various options
	km_insert_str,              // Always follows km_insert and used to store fill value string

	km_seed,                    // Seed random number generators 0 = random, 1 = from calc

	// Added in 3.2
	km_compress,                // 1 = compress, 2 = decompress, 0 = settings dlg

	// Added in 4.0
	km_comp_sync,               // 255 = sync now, 2 = toggle auto sync, 3 = toggle auto scroll
	km_last // = 242?           // Keep at end
};

// If/when we reach 255 we can recycle km_unused, km_invert, km_neg/km_inc/km_flip* etc
// Be careful to keep the numbers of all retained commands the same so that old
// keystroke macro files work in new versions of HexEdit.

enum convert_type  // used with km_convert
{
	CONVERT_ERROR,              // Keep zero as error value
	CONVERT_ASC2EBC,
	CONVERT_EBC2ASC,
	CONVERT_ANSI2IBM,
	CONVERT_IBM2ANSI,
	CONVERT_UPPER,
	CONVERT_LOWER,

	CONVERT_LAST                // Keep at end
};

// Note: Don't change these values as they may be stored on disk in macro files
//       You can, of course, add new values.
enum checksum_type  // used with km_checksum
{
	CHECKSUM_ERROR,

	// Simple "sum" checksums
	CHECKSUM_8 = 1,
	CHECKSUM_16,
	CHECKSUM_32,
	CHECKSUM_64,

	// CRCs
	CHECKSUM_CRC_CCITT = 11,
	CHECKSUM_CRC32,
	CHECKSUM_CRC16,
	CHECKSUM_CRC_CCITT_B,
	CHECKSUM_CRC_XMODEM,

	// Cryptographic checksums (hash codes)
	CHECKSUM_MD5 = 21,
	CHECKSUM_SHA1,
	CHECKSUM_SHA224,
	CHECKSUM_SHA256,
	CHECKSUM_SHA384,
	CHECKSUM_SHA512,

	// General CRC implementations (parameters supplied)
	// Note enum value minus 100 is the bit size.  We leave space for many other sizes in future (4,5,6,12,24,40 etc)
	CHECKSUM_CRC_4BIT = 104,
	CHECKSUM_CRC_8BIT = 108,
	CHECKSUM_CRC_16BIT = 116,
	CHECKSUM_CRC_32BIT = 132,
};

struct mouse_sel
{
	CPoint dev_down;            // Mouse down (device coordinates)
	CSizeAp doc_dist;           // Distance to mouse up (doc coords)
};

union copy_cchar                // see km_copy_cchar
{
	__int64 val;
	struct
	{
		unsigned int src_type : 3;
		unsigned int src_size : 3;
		unsigned int int_type : 3;
		unsigned int big_endian: 1;
		unsigned int hide_address: 1;
		unsigned int indent   : 7;
		unsigned int src_for  : 3;
		unsigned int align_cols: 1;
	};
};

#pragma pack(1)                 // Make sure macros fit into as little memory as possible
struct key_macro                // Stores one keystroke of the macro
{
//    km_type ktype;              // Type of keystroke
	unsigned char ktype;        // Type of "key" stored in a byte
	union
	{
		unsigned __int64 v64;   // Address or calc. value
		long vv;                // Character/key/flags etc
		CString *pss;           // Search string, file name etc
		LOGFONT *plf;           // Font attributes when font changed
		mouse_sel *pms;         // Mouse coords (km_mouse & km_shift_mouse)
	};

	// General constructor + default constructor (required by vector)
	key_macro(enum km_type k = km_unknown, unsigned __int64 v = 0)
		{ ktype = k; v64 = v; }
// Note to avoid ambiguous calls we had to get rid of the constructor below.  But this may cause
// portability problems since some keys values are now saved via v64 but replayed using vv.
// Because of the way unions (and little-endianness) works for this compiler this works OK for now.
//    key_macro(enum km_type k, long v = 0L)
//        { ktype = k; vv = v; }
	key_macro(enum km_type k, const CString &ss)
		{ ktype = k; pss = new CString(ss); }
	key_macro(enum km_type k, LOGFONT *p)
		{ ktype = k; plf = new LOGFONT; *plf = *p; }
	key_macro(enum km_type k, mouse_sel *p)
		{ ktype = k; pms = new mouse_sel; *pms = *p; }

	// Destructor
	~key_macro()
	{
		ASSERT(ktype != km_unknown);

		// Delete any allocated memory for specific km_type here
		if (ktype == km_find_text || ktype == km_replace_text || ktype == km_open ||
			ktype == km_macro_message || ktype == km_macro_play ||
			ktype == km_address_hex || ktype == km_address_dec ||
			ktype == km_encrypt_alg || ktype == km_encrypt_password ||
			ktype == km_bookmarks_add || ktype == km_bookmarks_goto ||
			ktype == km_import_motorola || ktype == km_import_intel || ktype == km_import_text ||
			ktype == km_new_str || ktype == km_insert_str ||
			ktype == km_read_file || ktype == km_focus || ktype == km_scheme ||
			ktype == km_expression)
			delete pss;
		else if (ktype == km_font)
			delete plf;
		else if (ktype == km_mouse || ktype == km_shift_mouse)
			delete pms;
	}

	// Copy constructor
	key_macro(const key_macro &from)
	{
		ASSERT(from.ktype != km_unknown);
		ktype = from.ktype;
		if (ktype == km_find_text || ktype == km_replace_text || ktype == km_open ||
			ktype == km_macro_message || ktype == km_macro_play ||
			ktype == km_address_hex || ktype == km_address_dec ||
			ktype == km_encrypt_alg || ktype == km_encrypt_password ||
			ktype == km_bookmarks_add || ktype == km_bookmarks_goto ||
			ktype == km_import_motorola || ktype == km_import_intel || ktype == km_import_text ||
			ktype == km_new_str || ktype == km_insert_str ||
			ktype == km_read_file || ktype == km_focus || ktype == km_scheme ||
			ktype == km_expression)
		{
			pss = new CString(*from.pss);
		}
		else if (ktype == km_font)
		{
			plf = new LOGFONT; *plf = *from.plf;
		}
		else if (ktype == km_mouse || ktype == km_shift_mouse)
		{
			pms = new mouse_sel; *pms = *from.pms;
		}
		else
			v64 = from.v64;               // Copy long by default (most used)
		// Dealloc/realloc memory for specific km_type here
	}
	// Assignment copy operator
	key_macro &operator=(const key_macro &from)
	{
		if (&from != this)
		{
			ASSERT(from.ktype != km_unknown);

			// Dealloc/realloc memory for existing km_type
			if (ktype == km_find_text || ktype == km_replace_text || ktype == km_open ||
				ktype == km_macro_message || ktype == km_macro_play ||
				ktype == km_address_hex || ktype == km_address_dec ||
				ktype == km_encrypt_alg || ktype == km_encrypt_password ||
				ktype == km_bookmarks_add || ktype == km_bookmarks_goto ||
				ktype == km_import_motorola || ktype == km_import_intel || ktype == km_import_text ||
				ktype == km_new_str || ktype == km_insert_str ||
				ktype == km_read_file || ktype == km_focus || ktype == km_scheme ||
				ktype == km_expression)
				delete pss;
			else if (ktype == km_font)
				delete plf;
			else if (ktype == km_mouse || ktype == km_shift_mouse)
				delete pms;

			// Allocate memory for new object and copy over
			ktype = from.ktype;
			if (ktype == km_find_text || ktype == km_replace_text || ktype == km_open ||
				ktype == km_macro_message || ktype == km_macro_play ||
				ktype == km_address_hex || ktype == km_address_dec ||
				ktype == km_encrypt_alg || ktype == km_encrypt_password ||
				ktype == km_bookmarks_add || ktype == km_bookmarks_goto ||
				ktype == km_import_motorola || ktype == km_import_intel || ktype == km_import_text ||
				ktype == km_new_str || ktype == km_insert_str ||
				ktype == km_read_file || ktype == km_focus || ktype == km_scheme ||
				ktype == km_expression)
			{
				pss = new CString(*from.pss);
			}
			else if (ktype == km_font)
			{
				plf = new LOGFONT; *plf = *from.plf;
			}
			else if (ktype == km_mouse || ktype == km_shift_mouse)
			{
				pms = new mouse_sel; *pms = *from.pms;
			}
			else
				v64 = from.v64;           // Copy long by default (most used)
		}
		return *this;
	}
	// These are required by vector<> under VC++ 5 even though not used
	bool operator==(const key_macro &) const { return false; }
	bool operator<(const key_macro &) const { return false; }
};
#pragma pack()
