// Room: /d/nanyang/jiulou1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "ӭ��¥");
    set("long", @LONG
��Բ������������ӭ��¥����˵�����˲�֪�����˲�����������
ѧʿ���ε��ˣ���ӭ��¥�������޲����ڣ���ȻΪ�����ң�����һ��
���麣�ڵļѻ����Ӵ�ӭ��¥��������¥�²��ü��ף��˿Ͷ��Ǵ�
�ҵ����ˣ������ӣ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
           __DIR__"/npc/xiaoer" : 1,
]));
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"nanyang",
  "up" : __DIR__"jiulou2",
]));
    setup();
    replace_program(ROOM);
}
