// Room: /d/huashan/baichi.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "�ٳ�Ͽ");
    set("long", @LONG
�߹�ǧ�ߴ���ǰ���ּ���һҪ���İٳ�Ͽ���ٳ�Ͽ����ǧ�ߴ����վ�
������ʮ�ֶ��ͣ��ұ�����������������������
LONG
    );
    set("no_clean_up", 0);
    set("outdoors", "huashan");
    set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"qianchi",
  "eastup" : __DIR__"laojun",
]));
    setup();
    replace_program(ROOM);
}
