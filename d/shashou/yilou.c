
inherit ROOM;
void init();

void create()
{
	set("short","��һ¥");
	set("long", @LONG
������ɱ��¥�ĵ�һ¥���߽����ͻ��һ������֮�⣬
�����ʮ�ֿտ����������յ��ƣ������Ǿ�׳�彣��ʿ��
��ɭ�ϱ��ˡ�������һ����������������һ������������д��
�������֡�ɱ  ��  ¥���������϶���һ�ˣ�����һϮ���£�
����ɱ��¥��¥��������Ц�������䡣
LONG
	   );
	set("exits",([
	    "south" : __DIR__"qiandian",
	   ]));
	set("objects",([
                      "/d/shashou/npc/daofengl" :1,
                      "/d/shashou/npc/shangfushi" :1,
                   "/d/shashou/npc/weishi":2,
			]));
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
