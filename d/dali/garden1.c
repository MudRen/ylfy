inherit ROOM;
void create()
{
        set("short", "ǰ��԰");
        set("long", @LONG
��������֮����������Լ�һ�ߣ��ı߻������࣬��Ψ��ĵ����ʤ���ǻ�����Ѱ
����¥��֮�࣬�ˡ�Ҧ�ơ���κ�ϡ�������Ʒ��һ����ֵ��ǧ���ǻ����������Ŷ��棬
��Χ�Ժ�ʯ��֮���仨���絤�̣���ɫ���ã��⻪��Ŀ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"garden",
]));

        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/huajiang" : 1,
]));
        set("outdoors","dali");

        setup();
}
