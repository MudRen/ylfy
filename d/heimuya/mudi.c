inherit ROOM;
void create()
{
    set("short", "Ĺ��");
	set("long", @LONG
�����Ǻ�ľ��������̽��ڵ�Ĺ�ء�Ĺ����Χ����һЩ�����Ļ�����
���ϵİ׻����ǵ�㡣�׻��м���һ�ߴ��ʯ��(bei)������Ĺ�ظ�
�ɾ�������Ȼ�������˴�ɨ��
LONG
	);
	set("exits", ([
        
        "west"      : __DIR__"grass1",
        ]));
	set("item_desc", ([
        "bei": "������ţ��������,��������\n"
	]) );
	setup();
        replace_program(ROOM);
}
