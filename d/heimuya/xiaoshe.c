//ROOM: xiaoshe.c
inherit ROOM;
void create()
{
	set("short", "С��");
        set("long",
	     "����һ���ô����ɵ�С��, һ����, ���ŵ�һ��Ũ�ҵĻ���, \n"
             "���й���һ����Ůͼ, ���������廨����, ������һ����, ����\n"
             "����һ��ĵ���Ľ�������. �ѵ�����˭�ҹ���Ĺ뷿? \n"
        );
        set("exits", ([
                "east" : __DIR__"guifang",
                "west" :__DIR__"xiaohuayuan",   
           ]));
        setup();
        replace_program(ROOM);
}
