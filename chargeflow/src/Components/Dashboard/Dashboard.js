import React, {useState} from "react";
// import {URL} from '../../config';
import Chart from "../Chart/Chart";
import AchievementCard from "../AchievementCard/AchievementCard";
import TopUsers from "../TopUsers/TopUsers";

const Dashboard = () => {
    const [orders, setOrders] = useState([
        {
            "id": 2523017871515,
            "email": "avr249@gmail.com",
            "closed_at": null,
            "created_at": "2020-06-26T02:08:30+03:00",
            "updated_at": "2020-06-26T02:08:30+03:00",
            "number": 8,
            "note": null,
            "token": "7160802d2fc9dd547b29e9c82d8b1075",
            "gateway": "paypal",
            "test": false,
            "total_price": "5.85",
            "subtotal_price": "5.00",
            "total_weight": 1000,
            "total_tax": "0.85",
            "taxes_included": false,
            "currency": "ILS",
            "financial_status": "paid",
            "confirmed": true,
            "total_discounts": "0.00",
            "total_line_items_price": "5.00",
            "cart_token": "",
            "buyer_accepts_marketing": false,
            "name": "#1008",
            "referring_site": "https://chf-avraham.myshopify.com/products/hello-product",
            "landing_site": "/wallets/checkouts.json",
            "cancelled_at": null,
            "cancel_reason": null,
            "total_price_usd": "1.70",
            "checkout_token": "cc5235107f9ce27bc32f96aefd423316",
            "reference": null,
            "user_id": null,
            "location_id": null,
            "source_identifier": null,
            "source_url": null,
            "processed_at": "2020-06-26T02:08:29+03:00",
            "device_id": null,
            "phone": null,
            "customer_locale": "en",
            "app_id": 580111,
            "browser_ip": "95.86.70.175",
            "landing_site_ref": null,
            "order_number": 1008,
            "discount_applications": [],
            "discount_codes": [],
            "note_attributes": [],
            "payment_gateway_names": [
                "paypal"
            ],
            "processing_method": "express",
            "checkout_id": 14314228416667,
            "source_name": "web",
            "fulfillment_status": null,
            "tax_lines": [
                {
                    "price": "0.85",
                    "rate": 0.17,
                    "title": "VAT",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        }
                    }
                }
            ],
            "tags": "",
            "contact_email": "avr249@gmail.com",
            "order_status_url": "https://chf-avraham.myshopify.com/41881862299/orders/7160802d2fc9dd547b29e9c82d8b1075/authenticate?key=b6e4f2b39c1b521fcc3814552932c608",
            "presentment_currency": "ILS",
            "total_line_items_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_discounts_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "total_shipping_price_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "subtotal_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_price_set": {
                "shop_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                }
            },
            "total_tax_set": {
                "shop_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                }
            },
            "line_items": [
                {
                    "id": 5548544098459,
                    "variant_id": 34720461750427,
                    "title": "hello product",
                    "quantity": 1,
                    "sku": "",
                    "variant_title": "",
                    "vendor": "chf_avraham",
                    "fulfillment_service": "manual",
                    "product_id": 5318448316571,
                    "requires_shipping": true,
                    "taxable": true,
                    "gift_card": false,
                    "name": "hello product",
                    "variant_inventory_management": "shopify",
                    "properties": [],
                    "product_exists": true,
                    "fulfillable_quantity": 1,
                    "grams": 1000,
                    "price": "5.00",
                    "total_discount": "0.00",
                    "fulfillment_status": null,
                    "price_set": {
                        "shop_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        }
                    },
                    "total_discount_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/LineItem/5548544098459",
                    "tax_lines": [
                        {
                            "title": "VAT",
                            "price": "0.85",
                            "rate": 0.17,
                            "price_set": {
                                "shop_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ],
                    "origin_location": {
                        "id": 2186028875931,
                        "country_code": "IL",
                        "province_code": "",
                        "name": "chf_avraham",
                        "address1": "beit israel 25 ",
                        "address2": "apartment 8",
                        "city": "emanuel",
                        "zip": "0044845"
                    }
                }
            ],
            "fulfillments": [],
            "refunds": [],
            "total_tip_received": "0.0",
            "original_total_duties_set": null,
            "current_total_duties_set": null,
            "admin_graphql_api_id": "gid://shopify/Order/2523017871515",
            "shipping_lines": [
                {
                    "id": 2100587626651,
                    "title": "Standard",
                    "price": "0.00",
                    "code": "Standard",
                    "source": "shopify",
                    "phone": null,
                    "requested_fulfillment_service_id": null,
                    "delivery_category": null,
                    "carrier_identifier": null,
                    "discounted_price": "0.00",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discounted_price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "tax_lines": []
                }
            ],
            "billing_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "0044845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "shipping_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "0044845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "client_details": {
                "browser_ip": "95.86.70.175",
                "accept_language": "he-IL,he;q=0.9,en-US;q=0.8,en;q=0.7,fr-BE;q=0.6,fr;q=0.5",
                "user_agent": "Mozilla/5.0 (Linux; Android 9; SM-G970F) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Mobile Safari/537.36",
                "session_hash": null,
                "browser_width": 360,
                "browser_height": 617
            },
            "customer": {
                "id": 3765495070875,
                "email": "avr249@gmail.com",
                "accepts_marketing": false,
                "created_at": "2020-06-23T18:00:09+03:00",
                "updated_at": "2020-06-26T02:08:30+03:00",
                "first_name": "avraham",
                "last_name": "avrahamu",
                "orders_count": 5,
                "state": "disabled",
                "total_spent": "20.48",
                "last_order_id": 2523017871515,
                "note": null,
                "verified_email": true,
                "multipass_identifier": null,
                "tax_exempt": false,
                "phone": null,
                "tags": "",
                "last_order_name": "#1008",
                "currency": "ILS",
                "accepts_marketing_updated_at": "2020-06-23T18:00:09+03:00",
                "marketing_opt_in_level": null,
                "tax_exemptions": [],
                "admin_graphql_api_id": "gid://shopify/Customer/3765495070875",
                "default_address": {
                    "id": 4421079629979,
                    "customer_id": 3765495070875,
                    "first_name": "avraham",
                    "last_name": "avrahamu",
                    "company": null,
                    "address1": "בית ישראל 25",
                    "address2": "דירה 8",
                    "city": "עמנו",
                    "province": null,
                    "country": "Israel",
                    "zip": "0044845",
                    "phone": null,
                    "name": "avraham avrahamu",
                    "province_code": null,
                    "country_code": "IL",
                    "country_name": "Israel",
                    "default": true
                }
            }
        },
        {
            "id": 2522713161883,
            "email": "avr248family@gmail.com",
            "closed_at": null,
            "created_at": "2020-06-25T22:34:33+03:00",
            "updated_at": "2020-06-25T22:34:34+03:00",
            "number": 7,
            "note": null,
            "token": "23fb0b882cae274b5296b222373455ef",
            "gateway": "paypal",
            "test": false,
            "total_price": "5.85",
            "subtotal_price": "5.00",
            "total_weight": 1000,
            "total_tax": "0.85",
            "taxes_included": false,
            "currency": "ILS",
            "financial_status": "paid",
            "confirmed": true,
            "total_discounts": "0.00",
            "total_line_items_price": "5.00",
            "cart_token": "25ca8c2e93831ba58b2c5c672b291560",
            "buyer_accepts_marketing": false,
            "name": "#1007",
            "referring_site": "android-app://com.google.android.gm/",
            "landing_site": "/",
            "cancelled_at": null,
            "cancel_reason": null,
            "total_price_usd": "1.70",
            "checkout_token": "211b441bf34bd0f8c1b7a028c75de129",
            "reference": null,
            "user_id": null,
            "location_id": null,
            "source_identifier": null,
            "source_url": null,
            "processed_at": "2020-06-25T22:34:32+03:00",
            "device_id": null,
            "phone": null,
            "customer_locale": "en",
            "app_id": 580111,
            "browser_ip": "95.86.70.175",
            "landing_site_ref": null,
            "order_number": 1007,
            "discount_applications": [],
            "discount_codes": [],
            "note_attributes": [],
            "payment_gateway_names": [
                "paypal"
            ],
            "processing_method": "express",
            "checkout_id": 14313582428315,
            "source_name": "web",
            "fulfillment_status": null,
            "tax_lines": [
                {
                    "price": "0.85",
                    "rate": 0.17,
                    "title": "VAT",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        }
                    }
                }
            ],
            "tags": "",
            "contact_email": "avr248family@gmail.com",
            "order_status_url": "https://chf-avraham.myshopify.com/41881862299/orders/23fb0b882cae274b5296b222373455ef/authenticate?key=3a54b138b11275cd1aad26441480fa0f",
            "presentment_currency": "ILS",
            "total_line_items_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_discounts_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "total_shipping_price_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "subtotal_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_price_set": {
                "shop_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                }
            },
            "total_tax_set": {
                "shop_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                }
            },
            "line_items": [
                {
                    "id": 5547959877787,
                    "variant_id": 34720461750427,
                    "title": "hello product",
                    "quantity": 1,
                    "sku": "",
                    "variant_title": "",
                    "vendor": "chf_avraham",
                    "fulfillment_service": "manual",
                    "product_id": 5318448316571,
                    "requires_shipping": true,
                    "taxable": true,
                    "gift_card": false,
                    "name": "hello product",
                    "variant_inventory_management": "shopify",
                    "properties": [],
                    "product_exists": true,
                    "fulfillable_quantity": 1,
                    "grams": 1000,
                    "price": "5.00",
                    "total_discount": "0.00",
                    "fulfillment_status": null,
                    "price_set": {
                        "shop_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        }
                    },
                    "total_discount_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/LineItem/5547959877787",
                    "tax_lines": [
                        {
                            "title": "VAT",
                            "price": "0.85",
                            "rate": 0.17,
                            "price_set": {
                                "shop_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ],
                    "origin_location": {
                        "id": 2186028875931,
                        "country_code": "IL",
                        "province_code": "",
                        "name": "chf_avraham",
                        "address1": "beit israel 25 ",
                        "address2": "apartment 8",
                        "city": "emanuel",
                        "zip": "0044845"
                    }
                }
            ],
            "fulfillments": [],
            "refunds": [],
            "total_tip_received": "0.0",
            "original_total_duties_set": null,
            "current_total_duties_set": null,
            "admin_graphql_api_id": "gid://shopify/Order/2522713161883",
            "shipping_lines": [
                {
                    "id": 2100371882139,
                    "title": "Standard",
                    "price": "0.00",
                    "code": "Standard",
                    "source": "shopify",
                    "phone": null,
                    "requested_fulfillment_service_id": null,
                    "delivery_category": null,
                    "carrier_identifier": null,
                    "discounted_price": "0.00",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discounted_price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "tax_lines": []
                }
            ],
            "billing_address": {
                "first_name": "תהילה",
                "address1": "הבעשט 10",
                "phone": null,
                "city": "עמנואל",
                "zip": "0044845",
                "province": null,
                "country": "Israel",
                "last_name": "אברהמי",
                "address2": "תד 150",
                "company": "",
                "latitude": null,
                "longitude": null,
                "name": "תהילה אברהמי",
                "country_code": "IL",
                "province_code": null
            },
            "shipping_address": {
                "first_name": "תהילה",
                "address1": "הבעשט 10",
                "phone": null,
                "city": "עמנואל",
                "zip": "0044845",
                "province": null,
                "country": "Israel",
                "last_name": "אברהמי",
                "address2": "תד 150",
                "company": "",
                "latitude": null,
                "longitude": null,
                "name": "תהילה אברהמי",
                "country_code": "IL",
                "province_code": null
            },
            "client_details": {
                "browser_ip": "95.86.70.175",
                "accept_language": "he-IL,he;q=0.9,en-US;q=0.8,en;q=0.7,fr-BE;q=0.6,fr;q=0.5",
                "user_agent": "Mozilla/5.0 (Linux; Android 9; SM-G970F) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Mobile Safari/537.36",
                "session_hash": null,
                "browser_width": 360,
                "browser_height": 617
            },
            "customer": {
                "id": 3766920380571,
                "email": "avr248family@gmail.com",
                "accepts_marketing": false,
                "created_at": "2020-06-24T02:48:16+03:00",
                "updated_at": "2020-06-26T01:27:32+03:00",
                "first_name": "תהילה",
                "last_name": "אברהמי",
                "orders_count": 3,
                "state": "disabled",
                "total_spent": "5.85",
                "last_order_id": 2522713161883,
                "note": null,
                "verified_email": true,
                "multipass_identifier": null,
                "tax_exempt": false,
                "phone": null,
                "tags": "",
                "last_order_name": "#1007",
                "currency": "ILS",
                "accepts_marketing_updated_at": "2020-06-24T02:48:16+03:00",
                "marketing_opt_in_level": null,
                "tax_exemptions": [],
                "admin_graphql_api_id": "gid://shopify/Customer/3766920380571",
                "default_address": {
                    "id": 4416355139739,
                    "customer_id": 3766920380571,
                    "first_name": "תהילה",
                    "last_name": "אברהמי",
                    "company": "",
                    "address1": "הבעשט 10",
                    "address2": "תד 150",
                    "city": "עמנואל",
                    "province": null,
                    "country": "Israel",
                    "zip": "0044845",
                    "phone": null,
                    "name": "תהילה אברהמי",
                    "province_code": null,
                    "country_code": "IL",
                    "country_name": "Israel",
                    "default": true
                }
            }
        },
        {
            "id": 2520704450715,
            "email": "avr249@gmail.com",
            "closed_at": null,
            "created_at": "2020-06-25T03:42:19+03:00",
            "updated_at": "2020-06-26T01:33:13+03:00",
            "number": 6,
            "note": null,
            "token": "ba8a857f1de88c4a36a1ae44f994f03f",
            "gateway": "paypal",
            "test": false,
            "total_price": "5.85",
            "subtotal_price": "5.00",
            "total_weight": 1000,
            "total_tax": "0.85",
            "taxes_included": false,
            "currency": "ILS",
            "financial_status": "refunded",
            "confirmed": true,
            "total_discounts": "0.00",
            "total_line_items_price": "5.00",
            "cart_token": "",
            "buyer_accepts_marketing": false,
            "name": "#1006",
            "referring_site": "https://chf-avraham.myshopify.com/products/hello-product",
            "landing_site": "/wallets/checkouts.json",
            "cancelled_at": null,
            "cancel_reason": null,
            "total_price_usd": "1.71",
            "checkout_token": "3b83f0f7ac252aba0a7ace5dbd8583a9",
            "reference": null,
            "user_id": null,
            "location_id": null,
            "source_identifier": null,
            "source_url": null,
            "processed_at": "2020-06-25T03:42:18+03:00",
            "device_id": null,
            "phone": null,
            "customer_locale": "en",
            "app_id": 580111,
            "browser_ip": "95.86.70.175",
            "landing_site_ref": null,
            "order_number": 1006,
            "discount_applications": [],
            "discount_codes": [],
            "note_attributes": [],
            "payment_gateway_names": [
                "paypal"
            ],
            "processing_method": "express",
            "checkout_id": 14310551945371,
            "source_name": "web",
            "fulfillment_status": null,
            "tax_lines": [
                {
                    "price": "0.85",
                    "rate": 0.17,
                    "title": "VAT",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        }
                    }
                }
            ],
            "tags": "",
            "contact_email": "avr249@gmail.com",
            "order_status_url": "https://chf-avraham.myshopify.com/41881862299/orders/ba8a857f1de88c4a36a1ae44f994f03f/authenticate?key=ec095e82bdd5b6b9aaf9dff8b4e48c43",
            "presentment_currency": "ILS",
            "total_line_items_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_discounts_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "total_shipping_price_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "subtotal_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_price_set": {
                "shop_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                }
            },
            "total_tax_set": {
                "shop_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                }
            },
            "line_items": [
                {
                    "id": 5544165769371,
                    "variant_id": 34720461750427,
                    "title": "hello product",
                    "quantity": 1,
                    "sku": "",
                    "variant_title": "",
                    "vendor": "chf_avraham",
                    "fulfillment_service": "manual",
                    "product_id": 5318448316571,
                    "requires_shipping": true,
                    "taxable": true,
                    "gift_card": false,
                    "name": "hello product",
                    "variant_inventory_management": "shopify",
                    "properties": [],
                    "product_exists": true,
                    "fulfillable_quantity": 1,
                    "grams": 1000,
                    "price": "5.00",
                    "total_discount": "0.00",
                    "fulfillment_status": null,
                    "price_set": {
                        "shop_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        }
                    },
                    "total_discount_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/LineItem/5544165769371",
                    "tax_lines": [
                        {
                            "title": "VAT",
                            "price": "0.85",
                            "rate": 0.17,
                            "price_set": {
                                "shop_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ],
                    "origin_location": {
                        "id": 2186028875931,
                        "country_code": "IL",
                        "province_code": "",
                        "name": "chf_avraham",
                        "address1": "beit israel 25 ",
                        "address2": "apartment 8",
                        "city": "emanuel",
                        "zip": "0044845"
                    }
                }
            ],
            "fulfillments": [],
            "refunds": [
                {
                    "id": 672261308571,
                    "order_id": 2520704450715,
                    "created_at": "2020-06-26T01:33:13+03:00",
                    "note": null,
                    "user_id": null,
                    "processed_at": "2020-06-26T01:33:13+03:00",
                    "restock": false,
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/Refund/672261308571",
                    "refund_line_items": [],
                    "transactions": [
                        {
                            "id": 3151579021467,
                            "order_id": 2520704450715,
                            "kind": "refund",
                            "gateway": "paypal",
                            "status": "success",
                            "message": "Manually refunded from PayPal",
                            "created_at": "2020-06-26T01:33:12+03:00",
                            "test": false,
                            "authorization": "3WK551665E336952U",
                            "location_id": null,
                            "user_id": null,
                            "parent_id": 3149329793179,
                            "processed_at": "2020-06-26T01:33:12+03:00",
                            "device_id": null,
                            "receipt": {
                                "mc_gross": "-5.85",
                                "invoice": "c14310551945371.1",
                                "protection_eligibility": "Eligible",
                                "item_number1": "",
                                "payer_id": "DGR68C3BF2GH6",
                                "address_street": "  25\r\n 8",
                                "payment_date": "15:33:05 Jun 25, 2020 PDT",
                                "payment_status": "Refunded",
                                "charset": "windows-1255",
                                "address_zip": "44845",
                                "mc_shipping": "0.00",
                                "mc_handling": "0.00",
                                "first_name": "avraham",
                                "mc_fee": "-1.40",
                                "address_country_code": "IL",
                                "address_name": "avraham avrahamu",
                                "notify_version": "3.9",
                                "reason_code": "refund",
                                "custom": "Shopify",
                                "business": "avr248@gmail.com",
                                "address_country": "Israel",
                                "mc_handling1": "0.00",
                                "address_city": "",
                                "verify_sign": "A88BdfLTmmfY.04iPO7p3xJTj8qdAti1UWNeAbw7SFV1KTbofMBYmWL6",
                                "payer_email": "avr249@gmail.com",
                                "mc_shipping1": "0.00",
                                "tax1": "0.00",
                                "parent_txn_id": "9SX05679K33551900",
                                "txn_id": "3WK551665E336952U",
                                "payment_type": "instant",
                                "last_name": "avrahamu",
                                "address_state": "N/A",
                                "item_name1": "hello product",
                                "receiver_email": "avr248@gmail.com",
                                "payment_fee": "",
                                "shipping_discount": "0.00",
                                "quantity1": "1",
                                "receiver_id": "KKWMCAT5PZBMW",
                                "insurance_amount": "0.00",
                                "discount": "0.00",
                                "mc_gross_1": "5.00",
                                "mc_currency": "ILS",
                                "residence_country": "IL",
                                "shipping_method": "Default",
                                "transaction_subject": "hello product",
                                "payment_gross": "",
                                "ipn_track_id": "ea83923fbc567"
                            },
                            "error_code": null,
                            "source_name": "web",
                            "amount": "5.85",
                            "currency": "ILS",
                            "admin_graphql_api_id": "gid://shopify/OrderTransaction/3151579021467"
                        }
                    ],
                    "order_adjustments": [
                        {
                            "id": 104518221979,
                            "order_id": 2520704450715,
                            "refund_id": 672261308571,
                            "amount": "-5.85",
                            "tax_amount": "0.00",
                            "kind": "refund_discrepancy",
                            "reason": "Refund discrepancy",
                            "amount_set": {
                                "shop_money": {
                                    "amount": "-5.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "-5.85",
                                    "currency_code": "ILS"
                                }
                            },
                            "tax_amount_set": {
                                "shop_money": {
                                    "amount": "0.00",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.00",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ]
                }
            ],
            "total_tip_received": "0.0",
            "original_total_duties_set": null,
            "current_total_duties_set": null,
            "admin_graphql_api_id": "gid://shopify/Order/2520704450715",
            "shipping_lines": [
                {
                    "id": 2099203539099,
                    "title": "Standard",
                    "price": "0.00",
                    "code": "Standard",
                    "source": "shopify",
                    "phone": null,
                    "requested_fulfillment_service_id": null,
                    "delivery_category": null,
                    "carrier_identifier": null,
                    "discounted_price": "0.00",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discounted_price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "tax_lines": []
                }
            ],
            "billing_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "44845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "shipping_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "44845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "client_details": {
                "browser_ip": "95.86.70.175",
                "accept_language": "he-IL,he;q=0.9,en-US;q=0.8,en;q=0.7,fr-BE;q=0.6,fr;q=0.5",
                "user_agent": "Mozilla/5.0 (Linux; Android 9; SM-G970F) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Mobile Safari/537.36",
                "session_hash": null,
                "browser_width": 360,
                "browser_height": 617
            },
            "customer": {
                "id": 3765495070875,
                "email": "avr249@gmail.com",
                "accepts_marketing": false,
                "created_at": "2020-06-23T18:00:09+03:00",
                "updated_at": "2020-06-26T02:08:30+03:00",
                "first_name": "avraham",
                "last_name": "avrahamu",
                "orders_count": 5,
                "state": "disabled",
                "total_spent": "20.48",
                "last_order_id": 2523017871515,
                "note": null,
                "verified_email": true,
                "multipass_identifier": null,
                "tax_exempt": false,
                "phone": null,
                "tags": "",
                "last_order_name": "#1008",
                "currency": "ILS",
                "accepts_marketing_updated_at": "2020-06-23T18:00:09+03:00",
                "marketing_opt_in_level": null,
                "tax_exemptions": [],
                "admin_graphql_api_id": "gid://shopify/Customer/3765495070875",
                "default_address": {
                    "id": 4421079629979,
                    "customer_id": 3765495070875,
                    "first_name": "avraham",
                    "last_name": "avrahamu",
                    "company": null,
                    "address1": "בית ישראל 25",
                    "address2": "דירה 8",
                    "city": "עמנו",
                    "province": null,
                    "country": "Israel",
                    "zip": "0044845",
                    "phone": null,
                    "name": "avraham avrahamu",
                    "province_code": null,
                    "country_code": "IL",
                    "country_name": "Israel",
                    "default": true
                }
            }
        },
        {
            "id": 2519805264027,
            "email": "avr249@gmail.com",
            "closed_at": null,
            "created_at": "2020-06-24T18:30:52+03:00",
            "updated_at": "2020-06-24T18:30:53+03:00",
            "number": 5,
            "note": null,
            "token": "9ab868c6132df3fb39c8ee82277969ec",
            "gateway": "paypal",
            "test": false,
            "total_price": "5.85",
            "subtotal_price": "5.00",
            "total_weight": 1000,
            "total_tax": "0.85",
            "taxes_included": false,
            "currency": "ILS",
            "financial_status": "paid",
            "confirmed": true,
            "total_discounts": "0.00",
            "total_line_items_price": "5.00",
            "cart_token": "f8bac3526c0fcb9b4915de215ddb0ccf",
            "buyer_accepts_marketing": false,
            "name": "#1005",
            "referring_site": "android-app://com.google.android.gm/",
            "landing_site": "/",
            "cancelled_at": null,
            "cancel_reason": null,
            "total_price_usd": "1.71",
            "checkout_token": "559b892a71683021368dd9c1d2e2ff86",
            "reference": null,
            "user_id": null,
            "location_id": null,
            "source_identifier": null,
            "source_url": null,
            "processed_at": "2020-06-24T18:30:51+03:00",
            "device_id": null,
            "phone": null,
            "customer_locale": "en",
            "app_id": 580111,
            "browser_ip": "2.53.51.254",
            "landing_site_ref": null,
            "order_number": 1005,
            "discount_applications": [],
            "discount_codes": [],
            "note_attributes": [],
            "payment_gateway_names": [
                "paypal"
            ],
            "processing_method": "express",
            "checkout_id": 14308724015259,
            "source_name": "web",
            "fulfillment_status": null,
            "tax_lines": [
                {
                    "price": "0.85",
                    "rate": 0.17,
                    "title": "VAT",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        }
                    }
                }
            ],
            "tags": "",
            "contact_email": "avr249@gmail.com",
            "order_status_url": "https://chf-avraham.myshopify.com/41881862299/orders/9ab868c6132df3fb39c8ee82277969ec/authenticate?key=54b840fe498e267c501e6a84d1d93327",
            "presentment_currency": "ILS",
            "total_line_items_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_discounts_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "total_shipping_price_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "subtotal_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_price_set": {
                "shop_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                }
            },
            "total_tax_set": {
                "shop_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                }
            },
            "line_items": [
                {
                    "id": 5542496272539,
                    "variant_id": 34720461750427,
                    "title": "hello product",
                    "quantity": 1,
                    "sku": "",
                    "variant_title": "",
                    "vendor": "chf_avraham",
                    "fulfillment_service": "manual",
                    "product_id": 5318448316571,
                    "requires_shipping": true,
                    "taxable": true,
                    "gift_card": false,
                    "name": "hello product",
                    "variant_inventory_management": "shopify",
                    "properties": [],
                    "product_exists": true,
                    "fulfillable_quantity": 1,
                    "grams": 1000,
                    "price": "5.00",
                    "total_discount": "0.00",
                    "fulfillment_status": null,
                    "price_set": {
                        "shop_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        }
                    },
                    "total_discount_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/LineItem/5542496272539",
                    "tax_lines": [
                        {
                            "title": "VAT",
                            "price": "0.85",
                            "rate": 0.17,
                            "price_set": {
                                "shop_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ],
                    "origin_location": {
                        "id": 2186028875931,
                        "country_code": "IL",
                        "province_code": "",
                        "name": "chf_avraham",
                        "address1": "beit israel 25 ",
                        "address2": "apartment 8",
                        "city": "emanuel",
                        "zip": "0044845"
                    }
                }
            ],
            "fulfillments": [],
            "refunds": [],
            "total_tip_received": "0.0",
            "original_total_duties_set": null,
            "current_total_duties_set": null,
            "admin_graphql_api_id": "gid://shopify/Order/2519805264027",
            "shipping_lines": [
                {
                    "id": 2098596282523,
                    "title": "Standard",
                    "price": "0.00",
                    "code": "Standard",
                    "source": "shopify",
                    "phone": null,
                    "requested_fulfillment_service_id": null,
                    "delivery_category": null,
                    "carrier_identifier": null,
                    "discounted_price": "0.00",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discounted_price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "tax_lines": []
                }
            ],
            "billing_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "44845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "shipping_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "44845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "client_details": {
                "browser_ip": "2.53.51.254",
                "accept_language": "he-IL,he;q=0.9,en-US;q=0.8,en;q=0.7,fr-BE;q=0.6,fr;q=0.5",
                "user_agent": "Mozilla/5.0 (Linux; Android 9; SM-G970F) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Mobile Safari/537.36",
                "session_hash": null,
                "browser_width": 360,
                "browser_height": 617
            },
            "customer": {
                "id": 3765495070875,
                "email": "avr249@gmail.com",
                "accepts_marketing": false,
                "created_at": "2020-06-23T18:00:09+03:00",
                "updated_at": "2020-06-26T02:08:30+03:00",
                "first_name": "avraham",
                "last_name": "avrahamu",
                "orders_count": 5,
                "state": "disabled",
                "total_spent": "20.48",
                "last_order_id": 2523017871515,
                "note": null,
                "verified_email": true,
                "multipass_identifier": null,
                "tax_exempt": false,
                "phone": null,
                "tags": "",
                "last_order_name": "#1008",
                "currency": "ILS",
                "accepts_marketing_updated_at": "2020-06-23T18:00:09+03:00",
                "marketing_opt_in_level": null,
                "tax_exemptions": [],
                "admin_graphql_api_id": "gid://shopify/Customer/3765495070875",
                "default_address": {
                    "id": 4421079629979,
                    "customer_id": 3765495070875,
                    "first_name": "avraham",
                    "last_name": "avrahamu",
                    "company": null,
                    "address1": "בית ישראל 25",
                    "address2": "דירה 8",
                    "city": "עמנו",
                    "province": null,
                    "country": "Israel",
                    "zip": "0044845",
                    "phone": null,
                    "name": "avraham avrahamu",
                    "province_code": null,
                    "country_code": "IL",
                    "country_name": "Israel",
                    "default": true
                }
            }
        },
        {
            "id": 2519540498587,
            "email": "avr248family@gmail.com",
            "closed_at": null,
            "created_at": "2020-06-24T15:43:31+03:00",
            "updated_at": "2020-06-26T01:27:28+03:00",
            "number": 4,
            "note": null,
            "token": "6c87360a703a5d8d05f83929cce0c3bf",
            "gateway": "paypal",
            "test": false,
            "total_price": "5.85",
            "subtotal_price": "5.00",
            "total_weight": 1000,
            "total_tax": "0.85",
            "taxes_included": false,
            "currency": "ILS",
            "financial_status": "refunded",
            "confirmed": true,
            "total_discounts": "0.00",
            "total_line_items_price": "5.00",
            "cart_token": "",
            "buyer_accepts_marketing": false,
            "name": "#1004",
            "referring_site": "https://chf-avraham.myshopify.com/products/hello-product",
            "landing_site": "/wallets/checkouts.json",
            "cancelled_at": null,
            "cancel_reason": null,
            "total_price_usd": "1.71",
            "checkout_token": "2bb27220f14c31abb8bfd518f220b827",
            "reference": null,
            "user_id": null,
            "location_id": null,
            "source_identifier": null,
            "source_url": null,
            "processed_at": "2020-06-24T15:43:30+03:00",
            "device_id": null,
            "phone": null,
            "customer_locale": "en",
            "app_id": 580111,
            "browser_ip": "95.86.70.175",
            "landing_site_ref": null,
            "order_number": 1004,
            "discount_applications": [],
            "discount_codes": [],
            "note_attributes": [],
            "payment_gateway_names": [
                "paypal"
            ],
            "processing_method": "express",
            "checkout_id": 14308071375003,
            "source_name": "web",
            "fulfillment_status": null,
            "tax_lines": [
                {
                    "price": "0.85",
                    "rate": 0.17,
                    "title": "VAT",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        }
                    }
                }
            ],
            "tags": "",
            "contact_email": "avr248family@gmail.com",
            "order_status_url": "https://chf-avraham.myshopify.com/41881862299/orders/6c87360a703a5d8d05f83929cce0c3bf/authenticate?key=53c8c91fc7f6874e53118c3946abb5c2",
            "presentment_currency": "ILS",
            "total_line_items_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_discounts_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "total_shipping_price_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "subtotal_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_price_set": {
                "shop_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                }
            },
            "total_tax_set": {
                "shop_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                }
            },
            "line_items": [
                {
                    "id": 5542065209499,
                    "variant_id": 34720461750427,
                    "title": "hello product",
                    "quantity": 1,
                    "sku": "",
                    "variant_title": "",
                    "vendor": "chf_avraham",
                    "fulfillment_service": "manual",
                    "product_id": 5318448316571,
                    "requires_shipping": true,
                    "taxable": true,
                    "gift_card": false,
                    "name": "hello product",
                    "variant_inventory_management": "shopify",
                    "properties": [],
                    "product_exists": true,
                    "fulfillable_quantity": 1,
                    "grams": 1000,
                    "price": "5.00",
                    "total_discount": "0.00",
                    "fulfillment_status": null,
                    "price_set": {
                        "shop_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        }
                    },
                    "total_discount_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/LineItem/5542065209499",
                    "tax_lines": [
                        {
                            "title": "VAT",
                            "price": "0.85",
                            "rate": 0.17,
                            "price_set": {
                                "shop_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ],
                    "origin_location": {
                        "id": 2186028875931,
                        "country_code": "IL",
                        "province_code": "",
                        "name": "chf_avraham",
                        "address1": "beit israel 25 ",
                        "address2": "apartment 8",
                        "city": "emanuel",
                        "zip": "0044845"
                    }
                }
            ],
            "fulfillments": [],
            "refunds": [
                {
                    "id": 672261111963,
                    "order_id": 2519540498587,
                    "created_at": "2020-06-26T01:27:28+03:00",
                    "note": null,
                    "user_id": null,
                    "processed_at": "2020-06-26T01:27:28+03:00",
                    "restock": false,
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/Refund/672261111963",
                    "refund_line_items": [],
                    "transactions": [
                        {
                            "id": 3151571288219,
                            "order_id": 2519540498587,
                            "kind": "refund",
                            "gateway": "paypal",
                            "status": "success",
                            "message": "Manually refunded from PayPal",
                            "created_at": "2020-06-26T01:27:28+03:00",
                            "test": false,
                            "authorization": "9WE609899H891115E",
                            "location_id": null,
                            "user_id": null,
                            "parent_id": 3148123668635,
                            "processed_at": "2020-06-26T01:27:28+03:00",
                            "device_id": null,
                            "receipt": {
                                "mc_gross": "-5.85",
                                "invoice": "c14308071375003.1",
                                "protection_eligibility": "Eligible",
                                "item_number1": "",
                                "payer_id": "5GXKPC63B3SNS",
                                "address_street": " 10\r\n 150",
                                "payment_date": "15:27:22 Jun 25, 2020 PDT",
                                "payment_status": "Refunded",
                                "charset": "windows-1255",
                                "address_zip": "0044845",
                                "mc_shipping": "0.00",
                                "mc_handling": "0.00",
                                "first_name": "",
                                "mc_fee": "-1.40",
                                "address_country_code": "IL",
                                "address_name": " ",
                                "notify_version": "3.9",
                                "reason_code": "refund",
                                "custom": "Shopify",
                                "business": "avr248@gmail.com",
                                "address_country": "Israel",
                                "mc_handling1": "0.00",
                                "address_city": "",
                                "verify_sign": "ARR6Q7mAuzLaULDQ76Sh6YCU6WjAAKK3dWsdqCggm7By3ssWZDRaDpCw",
                                "payer_email": "avr248family@gmail.com",
                                "mc_shipping1": "0.00",
                                "tax1": "0.00",
                                "parent_txn_id": "81P592178J913260F",
                                "txn_id": "9WE609899H891115E",
                                "payment_type": "instant",
                                "last_name": "",
                                "address_state": "N/A",
                                "item_name1": "hello product",
                                "receiver_email": "avr248@gmail.com",
                                "payment_fee": "",
                                "shipping_discount": "0.00",
                                "quantity1": "1",
                                "receiver_id": "KKWMCAT5PZBMW",
                                "insurance_amount": "0.00",
                                "discount": "0.00",
                                "mc_gross_1": "5.00",
                                "mc_currency": "ILS",
                                "residence_country": "IL",
                                "shipping_method": "Default",
                                "transaction_subject": "hello product",
                                "payment_gross": "",
                                "ipn_track_id": "5139ab3dacc9e"
                            },
                            "error_code": null,
                            "source_name": "web",
                            "amount": "5.85",
                            "currency": "ILS",
                            "admin_graphql_api_id": "gid://shopify/OrderTransaction/3151571288219"
                        }
                    ],
                    "order_adjustments": [
                        {
                            "id": 104518123675,
                            "order_id": 2519540498587,
                            "refund_id": 672261111963,
                            "amount": "-5.85",
                            "tax_amount": "0.00",
                            "kind": "refund_discrepancy",
                            "reason": "Refund discrepancy",
                            "amount_set": {
                                "shop_money": {
                                    "amount": "-5.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "-5.85",
                                    "currency_code": "ILS"
                                }
                            },
                            "tax_amount_set": {
                                "shop_money": {
                                    "amount": "0.00",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.00",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ]
                }
            ],
            "total_tip_received": "0.0",
            "original_total_duties_set": null,
            "current_total_duties_set": null,
            "admin_graphql_api_id": "gid://shopify/Order/2519540498587",
            "shipping_lines": [
                {
                    "id": 2098423234715,
                    "title": "Standard",
                    "price": "0.00",
                    "code": "Standard",
                    "source": "shopify",
                    "phone": null,
                    "requested_fulfillment_service_id": null,
                    "delivery_category": null,
                    "carrier_identifier": null,
                    "discounted_price": "0.00",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discounted_price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "tax_lines": []
                }
            ],
            "billing_address": {
                "first_name": "תהילה",
                "address1": "הבעשט 10",
                "phone": null,
                "city": "עמנואל",
                "zip": "0044845",
                "province": null,
                "country": "Israel",
                "last_name": "אברהמי",
                "address2": "תד 150",
                "company": "",
                "latitude": null,
                "longitude": null,
                "name": "תהילה אברהמי",
                "country_code": "IL",
                "province_code": null
            },
            "shipping_address": {
                "first_name": "תהילה",
                "address1": "הבעשט 10",
                "phone": null,
                "city": "עמנואל",
                "zip": "0044845",
                "province": null,
                "country": "Israel",
                "last_name": "אברהמי",
                "address2": "תד 150",
                "company": "",
                "latitude": null,
                "longitude": null,
                "name": "תהילה אברהמי",
                "country_code": "IL",
                "province_code": null
            },
            "client_details": {
                "browser_ip": "95.86.70.175",
                "accept_language": "he-IL,he;q=0.9,en-US;q=0.8,en;q=0.7,fr-BE;q=0.6,fr;q=0.5",
                "user_agent": "Mozilla/5.0 (Linux; Android 9; SM-G970F) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Mobile Safari/537.36",
                "session_hash": null,
                "browser_width": 360,
                "browser_height": 617
            },
            "customer": {
                "id": 3766920380571,
                "email": "avr248family@gmail.com",
                "accepts_marketing": false,
                "created_at": "2020-06-24T02:48:16+03:00",
                "updated_at": "2020-06-26T01:27:32+03:00",
                "first_name": "תהילה",
                "last_name": "אברהמי",
                "orders_count": 3,
                "state": "disabled",
                "total_spent": "5.85",
                "last_order_id": 2522713161883,
                "note": null,
                "verified_email": true,
                "multipass_identifier": null,
                "tax_exempt": false,
                "phone": null,
                "tags": "",
                "last_order_name": "#1007",
                "currency": "ILS",
                "accepts_marketing_updated_at": "2020-06-24T02:48:16+03:00",
                "marketing_opt_in_level": null,
                "tax_exemptions": [],
                "admin_graphql_api_id": "gid://shopify/Customer/3766920380571",
                "default_address": {
                    "id": 4416355139739,
                    "customer_id": 3766920380571,
                    "first_name": "תהילה",
                    "last_name": "אברהמי",
                    "company": "",
                    "address1": "הבעשט 10",
                    "address2": "תד 150",
                    "city": "עמנואל",
                    "province": null,
                    "country": "Israel",
                    "zip": "0044845",
                    "phone": null,
                    "name": "תהילה אברהמי",
                    "province_code": null,
                    "country_code": "IL",
                    "country_name": "Israel",
                    "default": true
                }
            }
        },
        {
            "id": 2518784671899,
            "email": "avr248family@gmail.com",
            "closed_at": null,
            "created_at": "2020-06-24T02:48:39+03:00",
            "updated_at": "2020-06-24T03:35:25+03:00",
            "number": 3,
            "note": null,
            "token": "4cabf76911fba3393e281f15f196c067",
            "gateway": "paypal",
            "test": false,
            "total_price": "5.85",
            "subtotal_price": "5.00",
            "total_weight": 1000,
            "total_tax": "0.85",
            "taxes_included": false,
            "currency": "ILS",
            "financial_status": "refunded",
            "confirmed": true,
            "total_discounts": "0.00",
            "total_line_items_price": "5.00",
            "cart_token": "",
            "buyer_accepts_marketing": false,
            "name": "#1003",
            "referring_site": "https://chf-avraham.myshopify.com/products/hello-product",
            "landing_site": "/wallets/checkouts.json",
            "cancelled_at": null,
            "cancel_reason": null,
            "total_price_usd": "1.70",
            "checkout_token": "245e97c8322b44599c8d5b9fb41dd493",
            "reference": null,
            "user_id": null,
            "location_id": null,
            "source_identifier": null,
            "source_url": null,
            "processed_at": "2020-06-24T02:48:39+03:00",
            "device_id": null,
            "phone": null,
            "customer_locale": "en",
            "app_id": 580111,
            "browser_ip": "2.52.78.226",
            "landing_site_ref": null,
            "order_number": 1003,
            "discount_applications": [],
            "discount_codes": [],
            "note_attributes": [],
            "payment_gateway_names": [
                "paypal"
            ],
            "processing_method": "express",
            "checkout_id": 14305681834139,
            "source_name": "web",
            "fulfillment_status": null,
            "tax_lines": [
                {
                    "price": "0.85",
                    "rate": 0.17,
                    "title": "VAT",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        }
                    }
                }
            ],
            "tags": "",
            "contact_email": "avr248family@gmail.com",
            "order_status_url": "https://chf-avraham.myshopify.com/41881862299/orders/4cabf76911fba3393e281f15f196c067/authenticate?key=d33232c83b27f806baf573695b43da1c",
            "presentment_currency": "ILS",
            "total_line_items_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_discounts_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "total_shipping_price_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "subtotal_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_price_set": {
                "shop_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                }
            },
            "total_tax_set": {
                "shop_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                }
            },
            "line_items": [
                {
                    "id": 5540785324187,
                    "variant_id": 34720461750427,
                    "title": "hello product",
                    "quantity": 1,
                    "sku": "",
                    "variant_title": "",
                    "vendor": "chf_avraham",
                    "fulfillment_service": "manual",
                    "product_id": 5318448316571,
                    "requires_shipping": true,
                    "taxable": true,
                    "gift_card": false,
                    "name": "hello product",
                    "variant_inventory_management": "shopify",
                    "properties": [],
                    "product_exists": true,
                    "fulfillable_quantity": 1,
                    "grams": 1000,
                    "price": "5.00",
                    "total_discount": "0.00",
                    "fulfillment_status": null,
                    "price_set": {
                        "shop_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        }
                    },
                    "total_discount_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/LineItem/5540785324187",
                    "tax_lines": [
                        {
                            "title": "VAT",
                            "price": "0.85",
                            "rate": 0.17,
                            "price_set": {
                                "shop_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ],
                    "origin_location": {
                        "id": 2186028875931,
                        "country_code": "IL",
                        "province_code": "",
                        "name": "chf_avraham",
                        "address1": "beit israel 25 ",
                        "address2": "apartment 8",
                        "city": "emanuel",
                        "zip": "0044845"
                    }
                }
            ],
            "fulfillments": [],
            "refunds": [
                {
                    "id": 672093208731,
                    "order_id": 2518784671899,
                    "created_at": "2020-06-24T03:35:25+03:00",
                    "note": null,
                    "user_id": null,
                    "processed_at": "2020-06-24T03:35:25+03:00",
                    "restock": false,
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/Refund/672093208731",
                    "refund_line_items": [],
                    "transactions": [
                        {
                            "id": 3147305549979,
                            "order_id": 2518784671899,
                            "kind": "refund",
                            "gateway": "paypal",
                            "status": "success",
                            "message": "Manually refunded from PayPal",
                            "created_at": "2020-06-24T03:35:25+03:00",
                            "test": false,
                            "authorization": "26N64209T9096420K",
                            "location_id": null,
                            "user_id": null,
                            "parent_id": 3147242537115,
                            "processed_at": "2020-06-24T03:35:25+03:00",
                            "device_id": null,
                            "receipt": {
                                "mc_gross": "-5.85",
                                "invoice": "c14305681834139.1",
                                "protection_eligibility": "Eligible",
                                "item_number1": "",
                                "payer_id": "5GXKPC63B3SNS",
                                "address_street": " 10\r\n 150",
                                "payment_date": "17:35:18 Jun 23, 2020 PDT",
                                "payment_status": "Refunded",
                                "charset": "windows-1255",
                                "address_zip": "0044845",
                                "mc_shipping": "0.00",
                                "mc_handling": "0.00",
                                "first_name": "",
                                "mc_fee": "-1.40",
                                "address_country_code": "IL",
                                "address_name": " ",
                                "notify_version": "3.9",
                                "reason_code": "refund",
                                "custom": "Shopify",
                                "business": "avr248@gmail.com",
                                "address_country": "Israel",
                                "mc_handling1": "0.00",
                                "address_city": "",
                                "verify_sign": "Aa5pWFUXthJ3W8kCVIgGj-lXFyzRAqQD0JujwNap13QAg9tNPj5B-ezO",
                                "payer_email": "avr248family@gmail.com",
                                "mc_shipping1": "0.00",
                                "tax1": "0.00",
                                "parent_txn_id": "40444553NU020225C",
                                "txn_id": "26N64209T9096420K",
                                "payment_type": "instant",
                                "last_name": "",
                                "address_state": "N/A",
                                "item_name1": "hello product",
                                "receiver_email": "avr248@gmail.com",
                                "payment_fee": "",
                                "shipping_discount": "0.00",
                                "quantity1": "1",
                                "receiver_id": "KKWMCAT5PZBMW",
                                "insurance_amount": "0.00",
                                "discount": "0.00",
                                "mc_gross_1": "5.00",
                                "mc_currency": "ILS",
                                "residence_country": "IL",
                                "shipping_method": "Default",
                                "transaction_subject": "hello product",
                                "payment_gross": "",
                                "ipn_track_id": "c040f02e5e8a0"
                            },
                            "error_code": null,
                            "source_name": "web",
                            "amount": "5.85",
                            "currency": "ILS",
                            "admin_graphql_api_id": "gid://shopify/OrderTransaction/3147305549979"
                        }
                    ],
                    "order_adjustments": [
                        {
                            "id": 104419360923,
                            "order_id": 2518784671899,
                            "refund_id": 672093208731,
                            "amount": "-5.85",
                            "tax_amount": "0.00",
                            "kind": "refund_discrepancy",
                            "reason": "Refund discrepancy",
                            "amount_set": {
                                "shop_money": {
                                    "amount": "-5.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "-5.85",
                                    "currency_code": "ILS"
                                }
                            },
                            "tax_amount_set": {
                                "shop_money": {
                                    "amount": "0.00",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.00",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ]
                }
            ],
            "total_tip_received": "0.0",
            "original_total_duties_set": null,
            "current_total_duties_set": null,
            "admin_graphql_api_id": "gid://shopify/Order/2518784671899",
            "shipping_lines": [
                {
                    "id": 2097869979803,
                    "title": "Standard",
                    "price": "0.00",
                    "code": "Standard",
                    "source": "shopify",
                    "phone": null,
                    "requested_fulfillment_service_id": null,
                    "delivery_category": null,
                    "carrier_identifier": null,
                    "discounted_price": "0.00",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discounted_price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "tax_lines": []
                }
            ],
            "billing_address": {
                "first_name": "תהילה",
                "address1": "הבעשט 10",
                "phone": null,
                "city": "עמנואל",
                "zip": "0044845",
                "province": null,
                "country": "Israel",
                "last_name": "אברהמי",
                "address2": "תד 150",
                "company": "",
                "latitude": null,
                "longitude": null,
                "name": "תהילה אברהמי",
                "country_code": "IL",
                "province_code": null
            },
            "shipping_address": {
                "first_name": "תהילה",
                "address1": "הבעשט 10",
                "phone": null,
                "city": "עמנואל",
                "zip": "0044845",
                "province": null,
                "country": "Israel",
                "last_name": "אברהמי",
                "address2": "תד 150",
                "company": "",
                "latitude": null,
                "longitude": null,
                "name": "תהילה אברהמי",
                "country_code": "IL",
                "province_code": null
            },
            "client_details": {
                "browser_ip": "2.52.78.226",
                "accept_language": "he-IL,he;q=0.9,en-US;q=0.8,en;q=0.7,fr-BE;q=0.6,fr;q=0.5",
                "user_agent": "Mozilla/5.0 (Linux; Android 9; SM-G970F) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Mobile Safari/537.36",
                "session_hash": null,
                "browser_width": 360,
                "browser_height": 617
            },
            "customer": {
                "id": 3766920380571,
                "email": "avr248family@gmail.com",
                "accepts_marketing": false,
                "created_at": "2020-06-24T02:48:16+03:00",
                "updated_at": "2020-06-26T01:27:32+03:00",
                "first_name": "תהילה",
                "last_name": "אברהמי",
                "orders_count": 3,
                "state": "disabled",
                "total_spent": "5.85",
                "last_order_id": 2522713161883,
                "note": null,
                "verified_email": true,
                "multipass_identifier": null,
                "tax_exempt": false,
                "phone": null,
                "tags": "",
                "last_order_name": "#1007",
                "currency": "ILS",
                "accepts_marketing_updated_at": "2020-06-24T02:48:16+03:00",
                "marketing_opt_in_level": null,
                "tax_exemptions": [],
                "admin_graphql_api_id": "gid://shopify/Customer/3766920380571",
                "default_address": {
                    "id": 4416355139739,
                    "customer_id": 3766920380571,
                    "first_name": "תהילה",
                    "last_name": "אברהמי",
                    "company": "",
                    "address1": "הבעשט 10",
                    "address2": "תד 150",
                    "city": "עמנואל",
                    "province": null,
                    "country": "Israel",
                    "zip": "0044845",
                    "phone": null,
                    "name": "תהילה אברהמי",
                    "province_code": null,
                    "country_code": "IL",
                    "country_name": "Israel",
                    "default": true
                }
            }
        },
        {
            "id": 2518231318683,
            "email": "avr249@gmail.com",
            "closed_at": null,
            "created_at": "2020-06-23T18:51:02+03:00",
            "updated_at": "2020-06-24T02:53:27+03:00",
            "number": 2,
            "note": null,
            "token": "8b26c9e449e2c49231d351eb8c41673f",
            "gateway": "paypal",
            "test": false,
            "total_price": "5.85",
            "subtotal_price": "5.00",
            "total_weight": 1000,
            "total_tax": "0.85",
            "taxes_included": false,
            "currency": "ILS",
            "financial_status": "partially_refunded",
            "confirmed": true,
            "total_discounts": "0.00",
            "total_line_items_price": "5.00",
            "cart_token": "b7d624094cd757347d07373e3da0dc67",
            "buyer_accepts_marketing": false,
            "name": "#1002",
            "referring_site": "android-app://com.google.android.gm/",
            "landing_site": "/",
            "cancelled_at": null,
            "cancel_reason": null,
            "total_price_usd": "1.70",
            "checkout_token": "2105acce8986526651a45c94eea1fe50",
            "reference": null,
            "user_id": null,
            "location_id": null,
            "source_identifier": null,
            "source_url": null,
            "processed_at": "2020-06-23T18:51:01+03:00",
            "device_id": null,
            "phone": null,
            "customer_locale": "en",
            "app_id": 580111,
            "browser_ip": "95.86.70.175",
            "landing_site_ref": null,
            "order_number": 1002,
            "discount_applications": [],
            "discount_codes": [],
            "note_attributes": [],
            "payment_gateway_names": [
                "paypal"
            ],
            "processing_method": "express",
            "checkout_id": 14304168181915,
            "source_name": "web",
            "fulfillment_status": null,
            "tax_lines": [
                {
                    "price": "0.85",
                    "rate": 0.17,
                    "title": "VAT",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        }
                    }
                }
            ],
            "tags": "",
            "contact_email": "avr249@gmail.com",
            "order_status_url": "https://chf-avraham.myshopify.com/41881862299/orders/8b26c9e449e2c49231d351eb8c41673f/authenticate?key=82dd42cadc56425980fe69c02af433bc",
            "presentment_currency": "ILS",
            "total_line_items_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_discounts_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "total_shipping_price_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "subtotal_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_price_set": {
                "shop_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                }
            },
            "total_tax_set": {
                "shop_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                }
            },
            "line_items": [
                {
                    "id": 5539739893915,
                    "variant_id": 34720461750427,
                    "title": "hello product",
                    "quantity": 1,
                    "sku": "",
                    "variant_title": "",
                    "vendor": "chf_avraham",
                    "fulfillment_service": "manual",
                    "product_id": 5318448316571,
                    "requires_shipping": true,
                    "taxable": true,
                    "gift_card": false,
                    "name": "hello product",
                    "variant_inventory_management": "shopify",
                    "properties": [],
                    "product_exists": true,
                    "fulfillable_quantity": 1,
                    "grams": 1000,
                    "price": "5.00",
                    "total_discount": "0.00",
                    "fulfillment_status": null,
                    "price_set": {
                        "shop_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        }
                    },
                    "total_discount_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/LineItem/5539739893915",
                    "tax_lines": [
                        {
                            "title": "VAT",
                            "price": "0.85",
                            "rate": 0.17,
                            "price_set": {
                                "shop_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ],
                    "origin_location": {
                        "id": 2186028875931,
                        "country_code": "IL",
                        "province_code": "",
                        "name": "chf_avraham",
                        "address1": "beit israel 25 ",
                        "address2": "apartment 8",
                        "city": "emanuel",
                        "zip": "0044845"
                    }
                }
            ],
            "fulfillments": [],
            "refunds": [
                {
                    "id": 672091340955,
                    "order_id": 2518231318683,
                    "created_at": "2020-06-24T02:53:27+03:00",
                    "note": null,
                    "user_id": null,
                    "processed_at": "2020-06-24T02:53:27+03:00",
                    "restock": false,
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/Refund/672091340955",
                    "refund_line_items": [],
                    "transactions": [
                        {
                            "id": 3147247517851,
                            "order_id": 2518231318683,
                            "kind": "refund",
                            "gateway": "paypal",
                            "status": "success",
                            "message": "Manually refunded from PayPal",
                            "created_at": "2020-06-24T02:53:27+03:00",
                            "test": false,
                            "authorization": "2E340530MV504225D",
                            "location_id": null,
                            "user_id": null,
                            "parent_id": 3146586325147,
                            "processed_at": "2020-06-24T02:53:27+03:00",
                            "device_id": null,
                            "receipt": {
                                "mc_gross": "-2.92",
                                "invoice": "c14304168181915.1",
                                "protection_eligibility": "Eligible",
                                "item_number1": "",
                                "payer_id": "DGR68C3BF2GH6",
                                "address_street": "  25\r\n 8",
                                "payment_date": "16:53:20 Jun 23, 2020 PDT",
                                "payment_status": "Refunded",
                                "charset": "windows-1255",
                                "address_zip": "44845",
                                "mc_shipping": "0.00",
                                "mc_handling": "0.00",
                                "first_name": "avraham",
                                "mc_fee": "-0.10",
                                "address_country_code": "IL",
                                "address_name": "avraham avrahamu",
                                "notify_version": "3.9",
                                "reason_code": "refund",
                                "custom": "Shopify",
                                "business": "avr248@gmail.com",
                                "address_country": "Israel",
                                "mc_handling1": "0.00",
                                "address_city": "",
                                "verify_sign": "A34dBjdvRDGbnGHQMebpzdgIVKx7Aw8nXMeuzEZqp6GpYZvnV9Nq9pPj",
                                "payer_email": "avr249@gmail.com",
                                "mc_shipping1": "0.00",
                                "tax1": "0.00",
                                "parent_txn_id": "4DA49740DS669521P",
                                "txn_id": "2E340530MV504225D",
                                "payment_type": "instant",
                                "last_name": "avrahamu",
                                "address_state": "N/A",
                                "item_name1": "hello product",
                                "receiver_email": "avr248@gmail.com",
                                "payment_fee": "",
                                "shipping_discount": "0.00",
                                "quantity1": "1",
                                "receiver_id": "KKWMCAT5PZBMW",
                                "insurance_amount": "0.00",
                                "discount": "0.00",
                                "mc_gross_1": "5.00",
                                "mc_currency": "ILS",
                                "residence_country": "IL",
                                "shipping_method": "Default",
                                "transaction_subject": "hello product",
                                "payment_gross": "",
                                "ipn_track_id": "9e7442b1ceec5"
                            },
                            "error_code": null,
                            "source_name": "web",
                            "amount": "2.92",
                            "currency": "ILS",
                            "admin_graphql_api_id": "gid://shopify/OrderTransaction/3147247517851"
                        }
                    ],
                    "order_adjustments": [
                        {
                            "id": 104418181275,
                            "order_id": 2518231318683,
                            "refund_id": 672091340955,
                            "amount": "-2.92",
                            "tax_amount": "0.00",
                            "kind": "refund_discrepancy",
                            "reason": "Refund discrepancy",
                            "amount_set": {
                                "shop_money": {
                                    "amount": "-2.92",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "-2.92",
                                    "currency_code": "ILS"
                                }
                            },
                            "tax_amount_set": {
                                "shop_money": {
                                    "amount": "0.00",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.00",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ]
                }
            ],
            "total_tip_received": "0.0",
            "original_total_duties_set": null,
            "current_total_duties_set": null,
            "admin_graphql_api_id": "gid://shopify/Order/2518231318683",
            "shipping_lines": [
                {
                    "id": 2097409982619,
                    "title": "Standard",
                    "price": "0.00",
                    "code": "Standard",
                    "source": "shopify",
                    "phone": null,
                    "requested_fulfillment_service_id": null,
                    "delivery_category": null,
                    "carrier_identifier": null,
                    "discounted_price": "0.00",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discounted_price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "tax_lines": []
                }
            ],
            "billing_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "44845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "shipping_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "44845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "client_details": {
                "browser_ip": "95.86.70.175",
                "accept_language": "he-IL,he;q=0.9,en-US;q=0.8,en;q=0.7,fr-BE;q=0.6,fr;q=0.5",
                "user_agent": "Mozilla/5.0 (Linux; Android 9; SM-G970F) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Mobile Safari/537.36",
                "session_hash": null,
                "browser_width": 360,
                "browser_height": 617
            },
            "customer": {
                "id": 3765495070875,
                "email": "avr249@gmail.com",
                "accepts_marketing": false,
                "created_at": "2020-06-23T18:00:09+03:00",
                "updated_at": "2020-06-26T02:08:30+03:00",
                "first_name": "avraham",
                "last_name": "avrahamu",
                "orders_count": 5,
                "state": "disabled",
                "total_spent": "20.48",
                "last_order_id": 2523017871515,
                "note": null,
                "verified_email": true,
                "multipass_identifier": null,
                "tax_exempt": false,
                "phone": null,
                "tags": "",
                "last_order_name": "#1008",
                "currency": "ILS",
                "accepts_marketing_updated_at": "2020-06-23T18:00:09+03:00",
                "marketing_opt_in_level": null,
                "tax_exemptions": [],
                "admin_graphql_api_id": "gid://shopify/Customer/3765495070875",
                "default_address": {
                    "id": 4421079629979,
                    "customer_id": 3765495070875,
                    "first_name": "avraham",
                    "last_name": "avrahamu",
                    "company": null,
                    "address1": "בית ישראל 25",
                    "address2": "דירה 8",
                    "city": "עמנו",
                    "province": null,
                    "country": "Israel",
                    "zip": "0044845",
                    "phone": null,
                    "name": "avraham avrahamu",
                    "province_code": null,
                    "country_code": "IL",
                    "country_name": "Israel",
                    "default": true
                }
            }
        },
        {
            "id": 2518157263003,
            "email": "avr249@gmail.com",
            "closed_at": null,
            "created_at": "2020-06-23T18:00:25+03:00",
            "updated_at": "2020-06-23T18:00:26+03:00",
            "number": 1,
            "note": null,
            "token": "6f047157772b5f4d03a507e112c212af",
            "gateway": "paypal",
            "test": false,
            "total_price": "5.85",
            "subtotal_price": "5.00",
            "total_weight": 1000,
            "total_tax": "0.85",
            "taxes_included": false,
            "currency": "ILS",
            "financial_status": "paid",
            "confirmed": true,
            "total_discounts": "0.00",
            "total_line_items_price": "5.00",
            "cart_token": "f1df9062377e3d9e2f50705dc396890f",
            "buyer_accepts_marketing": false,
            "name": "#1001",
            "referring_site": "",
            "landing_site": "/admin/auth/login?accountnumber=0&from_signup=true",
            "cancelled_at": null,
            "cancel_reason": null,
            "total_price_usd": "1.70",
            "checkout_token": "659a8e1e773ebffac8becf6f071e306e",
            "reference": null,
            "user_id": null,
            "location_id": null,
            "source_identifier": null,
            "source_url": null,
            "processed_at": "2020-06-23T18:00:24+03:00",
            "device_id": null,
            "phone": null,
            "customer_locale": "en",
            "app_id": 580111,
            "browser_ip": "95.86.70.175",
            "landing_site_ref": null,
            "order_number": 1001,
            "discount_applications": [],
            "discount_codes": [],
            "note_attributes": [],
            "payment_gateway_names": [
                "paypal"
            ],
            "processing_method": "express",
            "checkout_id": 14303983435931,
            "source_name": "web",
            "fulfillment_status": null,
            "tax_lines": [
                {
                    "price": "0.85",
                    "rate": 0.17,
                    "title": "VAT",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.85",
                            "currency_code": "ILS"
                        }
                    }
                }
            ],
            "tags": "",
            "contact_email": "avr249@gmail.com",
            "order_status_url": "https://chf-avraham.myshopify.com/41881862299/orders/6f047157772b5f4d03a507e112c212af/authenticate?key=6ad2caa79d762c33227fb9ead3e7c1b7",
            "presentment_currency": "ILS",
            "total_line_items_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_discounts_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "total_shipping_price_set": {
                "shop_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.00",
                    "currency_code": "ILS"
                }
            },
            "subtotal_price_set": {
                "shop_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.00",
                    "currency_code": "ILS"
                }
            },
            "total_price_set": {
                "shop_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "5.85",
                    "currency_code": "ILS"
                }
            },
            "total_tax_set": {
                "shop_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                },
                "presentment_money": {
                    "amount": "0.85",
                    "currency_code": "ILS"
                }
            },
            "line_items": [
                {
                    "id": 5539607183515,
                    "variant_id": 34720461750427,
                    "title": "hello product",
                    "quantity": 1,
                    "sku": "",
                    "variant_title": "",
                    "vendor": "chf_avraham",
                    "fulfillment_service": "manual",
                    "product_id": 5318448316571,
                    "requires_shipping": true,
                    "taxable": true,
                    "gift_card": false,
                    "name": "hello product",
                    "variant_inventory_management": "shopify",
                    "properties": [],
                    "product_exists": true,
                    "fulfillable_quantity": 1,
                    "grams": 1000,
                    "price": "5.00",
                    "total_discount": "0.00",
                    "fulfillment_status": null,
                    "price_set": {
                        "shop_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "5.00",
                            "currency_code": "ILS"
                        }
                    },
                    "total_discount_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "duties": [],
                    "admin_graphql_api_id": "gid://shopify/LineItem/5539607183515",
                    "tax_lines": [
                        {
                            "title": "VAT",
                            "price": "0.85",
                            "rate": 0.17,
                            "price_set": {
                                "shop_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                },
                                "presentment_money": {
                                    "amount": "0.85",
                                    "currency_code": "ILS"
                                }
                            }
                        }
                    ],
                    "origin_location": {
                        "id": 2186028875931,
                        "country_code": "IL",
                        "province_code": "",
                        "name": "chf_avraham",
                        "address1": "beit israel 25 ",
                        "address2": "apartment 8",
                        "city": "emanuel",
                        "zip": "0044845"
                    }
                }
            ],
            "fulfillments": [],
            "refunds": [],
            "total_tip_received": "0.0",
            "original_total_duties_set": null,
            "current_total_duties_set": null,
            "admin_graphql_api_id": "gid://shopify/Order/2518157263003",
            "shipping_lines": [
                {
                    "id": 2097347199131,
                    "title": "Standard",
                    "price": "0.00",
                    "code": "Standard",
                    "source": "shopify",
                    "phone": null,
                    "requested_fulfillment_service_id": null,
                    "delivery_category": null,
                    "carrier_identifier": null,
                    "discounted_price": "0.00",
                    "price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discounted_price_set": {
                        "shop_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        },
                        "presentment_money": {
                            "amount": "0.00",
                            "currency_code": "ILS"
                        }
                    },
                    "discount_allocations": [],
                    "tax_lines": []
                }
            ],
            "billing_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "44845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "shipping_address": {
                "first_name": "avraham",
                "address1": "בית ישראל 25",
                "phone": null,
                "city": "עמנו",
                "zip": "44845",
                "province": null,
                "country": "Israel",
                "last_name": "avrahamu",
                "address2": "דירה 8",
                "company": null,
                "latitude": null,
                "longitude": null,
                "name": "avraham avrahamu",
                "country_code": "IL",
                "province_code": null
            },
            "client_details": {
                "browser_ip": "95.86.70.175",
                "accept_language": "en-us",
                "user_agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_6) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.1.1 Safari/605.1.15",
                "session_hash": null,
                "browser_width": 1680,
                "browser_height": 939
            },
            "customer": {
                "id": 3765495070875,
                "email": "avr249@gmail.com",
                "accepts_marketing": false,
                "created_at": "2020-06-23T18:00:09+03:00",
                "updated_at": "2020-06-26T02:08:30+03:00",
                "first_name": "avraham",
                "last_name": "avrahamu",
                "orders_count": 5,
                "state": "disabled",
                "total_spent": "20.48",
                "last_order_id": 2523017871515,
                "note": null,
                "verified_email": true,
                "multipass_identifier": null,
                "tax_exempt": false,
                "phone": null,
                "tags": "",
                "last_order_name": "#1008",
                "currency": "ILS",
                "accepts_marketing_updated_at": "2020-06-23T18:00:09+03:00",
                "marketing_opt_in_level": null,
                "tax_exemptions": [],
                "admin_graphql_api_id": "gid://shopify/Customer/3765495070875",
                "default_address": {
                    "id": 4421079629979,
                    "customer_id": 3765495070875,
                    "first_name": "avraham",
                    "last_name": "avrahamu",
                    "company": null,
                    "address1": "בית ישראל 25",
                    "address2": "דירה 8",
                    "city": "עמנו",
                    "province": null,
                    "country": "Israel",
                    "zip": "0044845",
                    "phone": null,
                    "name": "avraham avrahamu",
                    "province_code": null,
                    "country_code": "IL",
                    "country_name": "Israel",
                    "default": true
                }
            }
        }
    ]);

    // const getOrders = async () => {
    //     const URL = 'https://9b390ddee43f258b0503e063002b7f79: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@chf-avraham.myshopify.com/admin/api/2020-04/orders.json'
    //
    //     const response = await fetch(URL);
    //     return await response.json();
    // };
    //
    // useEffect(() => {
    //     try {
    //         getOrders().then(data => {
    //             setOrders(data);
    //             console.log(data);
    //         });
    //     } catch (e) {
    //         console.log('err')
    //     }
    // }, []);

    const getMonthFromCreatedAt = (str) => {
        //str must start as : YYYY-MM-DD.....
        let month = '';
        month += str[5];
        month += str[6];

        return Number(month);
    }
    const getMonthlyOrders = () => {
        let monthlyOrders = Array(12);
        monthlyOrders.fill(0);
        const offset = -1; //months : 1 - 12 , array : 0 - 11

        orders.forEach(order => {
            const month = getMonthFromCreatedAt(order.created_at) + offset;
            ++monthlyOrders[month];
        })

        return monthlyOrders;
    }
    const getTotalSales = () => {
        let totalSales = 0;

        orders.forEach(order => {
            totalSales += Number(order['total_price']);
        })

        return totalSales;
    }
    const getNumOfOrders = () => {
        return orders.length;
    }
    const getTopUsers = () => {
        let users = {};

        orders.forEach(order => {
            users[order?.customer?.id] = {
                firstName: order?.customer?.first_name,
                lastName: order?.customer?.last_name,
                spent: order?.customer?.total_spent,
                numOfOrders: order?.customer?.orders_count
            };
        })

        let maxSpent = 0;
        let maxOrders = 0;

        let topSpent;
        let topOrders;

        let res = [];
        for (const userID in users) {
            let currUser = users[userID];
            const userSpent = Number(currUser.spent)
            const userOrders = currUser.numOfOrders

            if (userSpent > Number(maxSpent)) {
                maxSpent = users[userID].spent;
                topSpent = currUser;
            }
            if (userOrders > maxOrders) {
                maxOrders = userOrders;
                topOrders = currUser;
            }
        }
        res.push(topSpent);
        res.push(topOrders);
        return res;
    }


    return (
        <div className='dashboard'>
            <TopUsers topUsers={getTopUsers()}/>

            <div className='container'>
                <AchievementCard title='Revenue' value={getTotalSales()} currency='NIS'/>
                <AchievementCard title='Orders' value={getNumOfOrders()} currency={null}/>
            </div>
            <Chart monthlyOrders={getMonthlyOrders()}/>
        </div>
    );
}

export default Dashboard;