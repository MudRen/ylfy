// Room: /d/dali/chexiang.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��26�գ�����ʱ�䣺19ʱ13��58�롣

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������ڣ�������ĳ��輫Ϊ��������˹��̺��
�Ϻõ����Σ����������ƿ����Һ��������ţ����̲�ס���
�����ڡ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/wuliangye" : 1,
]));
	set("no_clean_up", 0);

	setup();
}

int do_check()
{
    object *obj;
    int i;
    obj=all_inventory(this_object());
    if (!sizeof(obj))   return 1;
    for (i=0;i<sizeof(obj);i++)
        if (userp(obj[i]))  return 0;
    return 1;
}
