// Room: /d/dali/wuqidian.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ36��59�롣

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ٶ�ϲ�������������ֵ��������ӻ�¯��ð���Ļ�⽫
ǽ��ͷӳ��ͨ�죬���ӵĽ���������˸�ʽ���������Ʒ��δ���Ʒ
�����ǳ������������ӡ������ȣ����������������õ��������졣
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dbdajie2",
]));
        set("objects", ([
                 "/d/city/npc/smith": 1,
]));

        setup();
}

