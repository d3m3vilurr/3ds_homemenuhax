typedef Result (*menuhaxcb_install)(char *menuhax_basefn);
typedef Result (*menuhaxcb_delete)(void);

#define MODULE_MAKE_CVER(major, minor, build) ((major<<16) | (minor<<8) | build)

typedef struct {
	int initialized;
	u32 index;
	u32 unsupported_cver;
	menuhaxcb_install haxinstall;
	menuhaxcb_delete haxdelete;
	bool themeflag;//The SD-cfg themeflag will be set to this once installation was successful.
} module_entry;

void register_module(module_entry *module);

Result menu_enablethemecache_persistent();
Result disablethemecache();
Result enablethemecache(u32 type, u32 shuffle, u32 index);

Result sd2themecache(char *body_filepath, char *bgm_filepath, u32 install_type);

extern u8 *filebuffer;
extern u32 filebuffer_maxsize;

