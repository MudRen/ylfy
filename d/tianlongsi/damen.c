// Room: /d/tianlongsi/damen.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
�������������´���ǰ��ֻ�����ƻֺ�������������Ͽ���һ������
( duilian )�����Ḳ�֣����е㲦����֮�⡣̧ͷ�����������һ���
ľ���ң����⡰��ʥ�¡��������֣�������ɡ�������ʽ�������������
�սй��ˣ�����֮Ϊ�������¡���
LONG
    );
    set("outdoors", "tianlongsi");
    set("item_desc", ([ /* sizeof() == 1 */
  "duilian" : "
    ������Ⱦ����Բ�ɡ�������Ե�������
",
]));
    set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"talin",
  "north" : __DIR__"dadao4",
]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
