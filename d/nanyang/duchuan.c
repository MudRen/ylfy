// Room: /d/shaolin/duchuan.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
        set("short", "�ɴ�");
        set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ�����������
�ֳֳ���ݣ����ڴ�β�����س��Ŵ���
LONG
        );
      set("outdoors","nanyang");
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
