inherit ITEM;

void create()
{
	set_name( "�ƻ���ľ������", ({ "gongfa pu", "pu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop", "�����������ܶ��ˣ���Ȼ�ù���׷���������鷳��\n");
		set("no_give", "��ô����Ķ�����ô������Ҹ����أ�\n");
		set("no_sell", "����Ҫ�ǹ���֪���˾��鷳�ˡ�\n");
		set("no_get", "���������ò�������\n");
		set("long", "����һ���ƻ���ľ����ͼ�����滭��һЩ����ֵֹĻ�ľ����ô��Ҳ��������ͼ��\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"yihua-jiemu",	
			"exp_required":	1000000,
			"dodge": 300,
			"int": 30,
			"dex": 40,
			"dodge": 300,
			"per": 22,
			"jing_cost": 10,
			"difficulty":	10,
			"max_skill":	350,
		]) );
	}
}
int query_autoload() { return 1; }