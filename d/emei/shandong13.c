// Room: /d/emei/shandong13.c ɽ��13
// create by host dec,20 1997

inherit ROOM;
void init();

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
������һ�����ɽ��������У���ʱ�е�ͷ��һ���ʹ��ֻ���ö�
��ʮ����խ�͵Ͱ������Ŷ����ұڻ���ǰ�У���ǽ����ɢ���������䳱ʪ
��Ϣ��ʹ�㲻�������Ĵ��˺��䣬������˵���������ܡ�
LONG
	);
        set("exits", ([
           "east":  __DIR__"shandong14",
           "west":  __DIR__"shandong12",
	]));
	setup();
}
