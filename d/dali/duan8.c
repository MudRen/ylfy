// Room: /d/dali/duan8.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺20ʱ44��13�롣

inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
�鷿��������Ŀ��ȫ��ʫ��伮���������ϰ������ͭ��������
�������ǹ�����Ϲ���һ��ˮī��������ȴ��һλ��װ��Ů������
���洫��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"duan6",
]));

        set("objects", ([
                __DIR__"npc/duanzc" : 1,
                __DIR__"npc/suicong" : 2,
        ]));

        setup();
}

