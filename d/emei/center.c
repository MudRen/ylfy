// Room: /d/emei/villagecenter.c  

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
��������Դ������ģ�һ������Ĺ㳡���ڹ㳡������һ����ȳ�����
������˹���ڹ㳡�����Ǹ�����ļ��У�ֻ�����������Ӳ�ʱ�Ĵ�����
��Ľ��������㳡�������һ��ͭ�ӣ�ƽ�ղ��෹�ᣬ�������Ů���ٶ���
��������̸��˵�ء�
LONG
	);

        set("exits", ([
              "south":__DIR__"sroad3",
	]));
        set("outdoors", "emei");
	setup();
}
