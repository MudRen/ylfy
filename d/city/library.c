// sexliterate.c 性文学房间
string look_wuxia();
string look_yanqing();
#define TUSHU_DIR "/doc/poem/story/"
inherit ROOM;
void create()
{
	set("short", "性文学图书馆");
	set("long", @LONG
    这是一间极为隐蔽的图书收藏室。你可以用 read 来阅读一些书,look书架的名字可以看到书籍列表! 现在有2个书架:
武侠类(wuxia) 言情类(yanqing)
上的黄色小说。
LONG
	);
        set("item_desc", ([
                "wuxia" : (: look_wuxia :),
                "yanqing" : (: look_yanqing :),
        ]));
//	set("exits", ([
//		"south" : __DIR__"lichunyuan",
//	]));
	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_read", "read");
}
string look_wuxia()
{
this_player()->start_more(read_file("/doc/poem/doc"));	
        return "\n";
}
string look_yanqing()
{
this_player()->start_more(read_file("/doc/poem/doc2"));	
        return "\n";
}
int do_read(string arg)
{
if (arg == "" || file_size(TUSHU_DIR + arg) <= 0)	
                return notify_fail("我们没有这本书。\n");
	switch (MONEY_D->player_pay(this_player(), 100000)) {
	        case 0:
                return notify_fail("穷光蛋，一边呆着去！\n");
	        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	}
	log_file("LIBRARY", sprintf("%s read %s.\n", this_player()->query("name"), arg));
this_player()->start_more(read_file(TUSHU_DIR + arg));	
	return 1;
}