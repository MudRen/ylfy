
inherit ITEM;
inherit F_FOOD;

void create()
{
  string name = "Ѭ����";
  set_name(name, ({"xun lachang", "lachang", "chang"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�����˴��ѵ�"+name+"��\n");
    set("unit", "��");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 25);
  }
}
int query_autoload() { return 1; }