// Room: /d/city/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ���������������̫ʦ
���Ͻ�ѧ���Ǿ��ǵ�������������ˡ�������������������ѧ��ѧ����һ�Ź�
�ⰻȻ���鰸������������ǰ�棬���ϰ��ż��������˵���װ�鼮����������
�����һ�����(shujia)�����ڶ��������ʯ�̣������Ժ��ʷ���ƾá�ֵ��
һ�����Ƕ�ڽ���ǰ��ڵ�ѧ��(xuegui)����Ժ�Ϸ��Ӹշ���ʥּ�䷢ѧλ��
�����ſ�������Ժ������ѧλ�����(board)��
LONG );
	set("item_desc", ([ /* sizeof() == 1 */
		"xuegui": "
		�ս����������տ���Ŀ��ҳ��
		ͨ��ʱ�������ζ�����ʫ����
		���������ʣ���ΰ�ʱ���ꡣ
		ҹ���Խ���������Ҫ������

	               ֪ʶ�޼ۡ�\n",
		"shujia":"һ��һ����Ⱦ����ܡ�\n",
		"board": "
       ����Ժ��ʥ�϶�ּ�Լ��������ѧλ��
\n" 
	]));
set("exits", ([ /* sizeof() == 3 */	
		"north"    : __DIR__"shuyuan2",
"up"    : __DIR__"xxci1",	
		"south" : __DIR__"dongdajie1",
	]));
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/zhu" : 1,   	
	]));
//      set("no_clean_up", 0);	

	setup();
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && (userp(me) && !wizardp(me)))
                return notify_fail("���������˽�����ң���\n");
        return 1;
}

