// Wenwu 2003.8.22
// tong.c
inherit ITEM;
void create()
{
set_name("ͭ", ({"copper"}));
set_weight(130000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "��");
set("long",
"һ����ͭ������ϡ���Էֱ��ͭ�˶��ѵ��ֽš�\n");
set("value",2000);
set("material", "iron");
}
}
