// Room: hangzhou/city/shuoshuyuan.c
// JXX 1998/06/26 

inherit ROOM;

void create()
{
	set("short", "˵��Ժ");
	set("long", @LONG
����������ȫ�������������ű������ݣ���Ȼ������¡����
����һ�������������ӡ���������������ʦ���洫���󲿷�ʱ��
��������˵�顣�����������ף��Ժ��ζ�������Ϊ���ѱ����ʦ�š�
С�������������������������ί����������Ϊ�������񡱡�
LONG
	);

	set("exits", ([
                "east" : __DIR__"cdshuchang",
	]));

	set("objects", ([
                __DIR__"npc/wangcheng" : 1,
                __DIR__"npc/shenjinyin" : 1,
	]));

	setup();
	replace_program(ROOM);
}

