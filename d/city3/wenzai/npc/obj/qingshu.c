//bye enter

inherit ITEM;
void create()
{
        set_name( "����", ({ "qing shu"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǰ����͸���������飬��ɲ�Ҫ˽�Դ�����Ŷ��\n");
              }
}
int query_autoload() { return 1; }