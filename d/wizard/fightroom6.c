// Room: /d/wizard/fightroom6.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "��������");
    set("long", @LONG
����һ�����������ģ��ɾ�Ө�İ���ܳɵĳ��ȡ�����������
�޼�����Ļ��ݣ�΢�紵��������Ϯ�ˡ���ɫ�ľ�ʯ�����������
���˵�ɫ�ʡ�һ���Ե���������������
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fightroom5",
]));
    setup();
    replace_program(ROOM);
}
