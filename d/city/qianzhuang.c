// Room: /city/qianzhuang.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ������̨����һ������(paizi)��
LONG
	);
	set("exits", ([
		"east" : __DIR__"beidajie1",
		//"up" : __DIR__"chucangshi",
	]));
        set("item_desc", ([
                "paizi": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�
convert(huan)     �һ�Ǯ�ҡ�
deposit(cun)      ��Ǯ��
withdraw(qu)      ȡǮ��
check(cha)        ��ѯ��
zhuan       ת�˹��ܣ�ÿ������1G�����100��,��������
ÿ��ȡǮ������ɰٷ�֮һ�������ѣ���ׯ�����Ĵ���п�ȡ��
TEXT
        ]) );
	set("objects", ([
                __DIR__"npc/qian" : 1,
              "/d/npc/xunbu": 1,
	]));
  set("no_fight",1);
	setup();
	replace_program(ROOM);
}
