// Room: /d/dali/zhahuodian.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺22ʱ12��39�롣

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
�����Ǵ���ǵ��ӻ��̡�ר�ž�ӪһЩ�����ճ��õ�������Ʒ��
�����ϰ����˺��ƣ���������Ķ�������ʵ�ݣ��������������һֱ
��������ǽ�ļ����ϰ����������������Ʒ���м�һ�Ź�̨������
�������ڹ�̨�������ʡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongdajie2",
]));
        set("objects", ([
                __DIR__"npc/zhen" : 1,
        ]));

	setup();
}
