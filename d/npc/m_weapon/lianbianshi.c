// Room: /d/npc/m_weapon/lianbianshi.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "���̶");
    set("long", @LONG
�����������Ŷ��Ĵ���ֱ޵ĵط������ڻ������̵ĸ��̲�ϡ���Ȼ������
��һ��Ư����̶ˮ���������˲��ò���̾����Ȼ�Ĺ��񹤡�̶������վ��һλ
�������Ů�����а�����һ�ѿ��Ƽ��Ƿ�����ذ�ף������Ŀ��������̶ˮ����
LONG
    );
    set("no_clean_up", 0);
    set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shibian" : 1,
]));
    set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/xingxiu/luzhou",
]));
    setup();
    replace_program(ROOM);
}
