// dujing1.c

inherit ITEM;

void create()
{
	set_name("¶¾¾­ÉÏÆª", ({ "jing", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "±¾");
		set("long", "ÕâÊÇÒ»±¾±¡±¡µÄĞ¡²á£¬ÉÏÃæÃÜÃÜÂéÂéµÄĞ´ÂúÁË¸÷ÖÖÓÃ¶¾µÄ»ù±¾·½·¨ºÍ¶¾Ò©µÄÅä·½¡£\nÄã¿ÉÒÔÓÃ(see)¿´Ò»¿´¡£\n");
		set("value", 0);
		set("material", "silk");
		set("skill", ([
			"name":	"duji",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
}
void init()
{
	add_action("do_read","see");
}
int do_read(string arg)
{
  if(arg=="jing"||arg=="book")
	return notify_fail("\n  Îå¶¾½ÌÁéÒ©Åä·½¼°¹¦Ğ§£º\n
       ÉßĞÅ×Ó+Éß¶¾ÄÒ------>ºìÉ«Ò©·Û(red yao)----->Éß¶¾\n
       ´©ĞÄÁ«+òÚò¼¶¾ÄÒ---->»ÆÉ«Ò©·Û(yellow yao)----->òÚò¼¶¾\n
       ¸¯¹Ç²İ+Ö©Öë¶¾ÄÒ---->ÂÌÉ«Ò©·Û(green yao)----->Ö©Öë¶¾\n
       º×¶¥ºì+Ğ«×Ó¶¾ÄÒ---->°×É«Ò©·Û(white yao)----->Ğ«×Ó¶¾\n
       ¶Ï³¦²İ+ó¸òÜ¶¾ÄÒ---->ºÚÉ«Ò©·Û(black yao)----->ó¸òÜ¶¾\n
       Ç§ÈÕ×í+½ğÉß¶¾Òº---->ÉñÏÉµ¹(shenxiandao)------->ÃÔ»êÒ©\n
");
}
int query_autoload() { return 1; }