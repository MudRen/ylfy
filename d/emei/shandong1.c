// Room: /d/emei/shandong1.c ɽ��1
// create by host dec,20 1997

inherit ROOM;

void init();

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
����ǰ��Ȼһ�ڣ������У���ʱ�е�ͷ��һ���ʹ��ֻ���ö���ʮ
����խ�͵Ͱ������Ŷ����ұڻ���ǰ�У���ǽ����ɢ���������䳱ʪ��
Ϣ��ʹ�㲻�������Ĵ��˺��䣬������˵���������ܡ�
LONG
	);
        set("exits", ([
           "east":  __DIR__"shandong"+(random(6)+5),
           "west":  __DIR__"dongkou",
           "south": __DIR__"shandong"+(random(6)+5),
           "north": __DIR__"shandong2", 
	]));
	setup();
}
