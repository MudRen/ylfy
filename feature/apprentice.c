// apprentice.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <dbase.h>

// 是否是ob的徒弟
int is_apprentice_of(object ob)
{
    mapping family;
    
    if ( !mapp(family = query("family")) )
		return 0;
	
	/*if ( family["family_name"] != (string)ob->query("family/family_name") )
		return 0;

	if ( family["generation"] != (int)ob->query("family/generation") + 1 )
		return 0;*/
    
	if ( family["master_id"] == (string)ob->query("id") 
		&& family["master_name"] == (string)ob->query("name") )
		return 1;
    
	return 0;
    
}
// 是否是ob的师傅
int recognize_apprentice(object ob)
{
	mapping family, my_family;
	
	if ( !mapp(my_family = query("family")) ) return 0; // 师傅无门派
	if ( !mapp(family = ob->query("family")) ) return 0; // 徒弟无门牌
	if ( !stringp(my_family["family_name"]) || !stringp(family["family_name"]) ) return 0; // 门牌名称无效
	if ( my_family["family_name"] != family["family_name"] ) return 0; // 师傅和徒弟不在同一个门牌
	if ( family["generation"] != my_family["generation"] + 1 ) return 0; // 徒弟和师傅的辈份不符合
	if ( family["master_id"] == query("id") && family["master_name"] == query("name") ) return 1;
	return 0;
}

void assign_apprentice(string title, int privs)
{
    mapping family;

	if( !mapp(family = query("family")) ) return;
	family["title"] = title;
	family["privs"] = privs;
	if( userp(this_object()) || !query("title") ) 
	{
		if( family["generation"]==1 )
			set("title", family["family_name"] + "开山祖师");
		else
			set("title", sprintf("%s第%s代%s", family["family_name"], 
				chinese_number(family["generation"]), family["title"]));
	}
}
// This is used for NPC, or start a new family for a player.
void create_family(string family_name, int generation, string title)
{
    mapping family;
    family = allocate_mapping(6);
    family["family_name"] = family_name;
    family["generation"] = generation;
    set("family", family);
    // priv = -1 for ALL privileges.
    assign_apprentice( title, -1 );
}
int recruit_apprentice(object ob)
{
    mapping my_family, family;

    if( ob->is_apprentice_of( this_object() ) ) return 0;
    if( !mapp(my_family = query("family")) ) return 0;
    
	family = allocate_mapping(sizeof(my_family));
	family["master_id"] = query("id");
	family["master_name"] = query("name");
	family["family_name"] = my_family["family_name"];
	family["generation"] = my_family["generation"] + 1;
	family["enter_time"] = time();
	ob->set("family", family);
    ob->assign_apprentice("弟子", 0);
    return 1;
}
