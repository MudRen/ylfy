
inherit ROOM;
void init();

void create()
{
	set("short","ǰ��");
	set("long", @LONG
������ɱ��¥��ǰ������ǽ��ʯ�̳ɵĺ���
����������������ܻ������������ܳ缹�����ư�
�磬���￴��������ɭ�ϡ�
LONG
	   );
	set("exits",([/* sizeof()==5 */
          "south" : __DIR__"jiaochang",
	    "north" : __DIR__"yilou",
	    "west" : __DIR__"erlou",
	    "east" : __DIR__"sanlou",
	   ]));
	set("objects",([
                __DIR__"npc/weishi":2,
			]));
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
