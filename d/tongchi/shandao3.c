inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG 
ˮ��Խ��Խ��ɽ�������ŨŨ��ˮ����ʯ���ϣ����ѵ�ɽ
϶�У�������һ����ϸϸ��Ȫˮ�����һ�ɳα̵�СϪ����ɽ��
������ȥ����Χ���⵴���������������������ɾ���
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
 ]));
    set("no_clean_up", 0);
    set("outdoors", "tongchi");
    set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"hu",
  "northup" : __DIR__"shandao4",
]));
    setup();
    replace_program(ROOM);
}
