
inherit ROOM;
void init();

void create()
{
	set("short","����¥");
	set("long", @LONG
������ɱ��¥�ĵ���¥�������ס����ɱ��¥����
��һ���ĸ��֡�����������ںڵģ�ֻ��һ˿΢���Ĺ�
�ߴ�ǽ�ϵĴ�����͸������
LONG
	   );
	set("exits",([
           "west" : __DIR__"qiandian",
	   ]));
	set("objects",([
		      __DIR__"npc/xiaobai":1,
		      __DIR__"npc/xiaohei":1,
                    __DIR__"npc/weishi":2,
			]));
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
