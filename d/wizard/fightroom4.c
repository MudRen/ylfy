// Room: /d/wizard/fightroom4.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "ʯ����");
    set("long", @LONG
ֻ����������Ͳ�������������Ÿ����ϸ�������������Ϳ�Σ���һɫˮ
ĥȺǽ����ʯ̨�ף��������������������ѩ�׷�ǽ�����滢Ƥʯ����������
�ŵ�����Ҹ�һ��̴ľ���ң����Ͽ��š��� �� �� �ѡ��ĸ��̽���֡�
LONG
    );
    set("exits", ([ 
  "west" : __DIR__"fightroom5",
  "north" : __DIR__"fightroom1",
]));
    setup();
}
