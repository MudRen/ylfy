// Room: /d/dali/shuyuan.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ34��50�롣

inherit ROOM;

void create()
{
	set("short", "�����ֹ�");
	set("long", @LONG
�����������ƾõ���ʷ���������³�ʫ����ʫ�꡻���䶨ʯ�̡�
��گ������»Ȱʯ�̡������¡����������İ������ס�������һ����
��������������д����ë�ʻ���ǩд��ֽ��ײ��ϡ��������һ����
ѧ��Ϊ�˴�д���ţ����ģ���Լ�ȵȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"nandajie2",
  "west" : __DIR__"shuyuan2",
]));

        set("objects", ([
                __DIR__"npc/zhu" : 1,
        ]));

	setup();
}
