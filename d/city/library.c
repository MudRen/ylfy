// sexliterate.c ����ѧ����
string look_wuxia();
string look_yanqing();
#define TUSHU_DIR "/doc/poem/story/"
inherit ROOM;
void create()
{
	set("short", "����ѧͼ���");
	set("long", @LONG
    ����һ�伫Ϊ���ε�ͼ���ղ��ҡ�������� read ���Ķ�һЩ��,look��ܵ����ֿ��Կ����鼮�б�! ������2�����:
������(wuxia) ������(yanqing)
�ϵĻ�ɫС˵��
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
                return notify_fail("����û���Ȿ�顣\n");
	switch (MONEY_D->player_pay(this_player(), 100000)) {
	        case 0:
                return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	        case 2:
                return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	}
	log_file("LIBRARY", sprintf("%s read %s.\n", this_player()->query("name"), arg));
this_player()->start_more(read_file(TUSHU_DIR + arg));	
	return 1;
}