import { useState } from 'react';

export default function Contact() {
    const [submitted, setSubmitted] = useState(false);

    const handleSubmit = (e) => {
        e.preventDefault();
        setSubmitted(true);
    };

    return (
        <div className="max-w-3xl mx-auto px-6 py-16">
            <h1 className="text-4xl font-bold text-gray-800 mb-8 text-center">Kontakt</h1>

            <p className="text-lg text-gray-700 mb-10 text-center">
                Masz pytania? Skontaktuj się z nami, a odpowiemy najszybciej jak to możliwe.
            </p>

            <div className="bg-white shadow-md rounded-lg p-6 space-y-6">
                <div className="space-y-2">
                    <h2 className="text-xl font-semibold text-blue-600">Dane kontaktowe</h2>
                    <p className="text-gray-700">
                        📧 Email:{' '}
                        <a href="mailto:kontakt@mcs-system.pl" className="text-blue-600 hover:underline">
                            kontakt@mcs-system.pl
                        </a>
                    </p>
                    <p className="text-gray-700">
                        📞 Telefon:{' '}
                        <a href="tel:+48123456789" className="text-blue-600 hover:underline">
                            +48 123 456 789
                        </a>
                    </p>
                    <p className="text-gray-700">
                        🏢 Adres:{' '}
                        <a
                            href="https://maps.google.com?q=ul.+Częściowa+10,+Warszawa"
                            target="_blank"
                            rel="noopener noreferrer"
                            className="text-blue-600 hover:underline"
                        >
                            ul. Częściowa 10, 00-000 Warszawa
                        </a>
                    </p>
                </div>

                <form onSubmit={handleSubmit} className="space-y-4">
                    <div>
                        <label className="block text-sm text-gray-700 mb-1">Imię i nazwisko *</label>
                        <input
                            type="text"
                            required
                            className="w-full border border-gray-300 rounded px-4 py-2 focus:outline-none focus:ring-2 focus:ring-blue-500"
                            placeholder="Jan Kowalski"
                        />
                    </div>
                    <div>
                        <label className="block text-sm text-gray-700 mb-1">Adres e-mail *</label>
                        <input
                            type="email"
                            required
                            className="w-full border border-gray-300 rounded px-4 py-2 focus:outline-none focus:ring-2 focus:ring-blue-500"
                            placeholder="jan@example.com"
                        />
                    </div>
                    <div>
                        <label className="block text-sm text-gray-700 mb-1">Wiadomość *</label>
                        <textarea
                            required
                            className="w-full border border-gray-300 rounded px-4 py-2 focus:outline-none focus:ring-2 focus:ring-blue-500"
                            rows="4"
                            placeholder="Treść wiadomości..."
                        ></textarea>
                    </div>
                    <button
                        type="submit"
                        className="bg-blue-600 hover:bg-blue-700 text-white px-6 py-2 rounded shadow w-full"
                    >
                        Wyślij wiadomość
                    </button>
                    {submitted && (
                        <p className="text-green-600 font-medium mt-2">Dziękujemy! Wiadomość została wysłana.</p>
                    )}
                </form>

                {/* Opcjonalnie mapa */}
                <div className="pt-8">
                    <iframe
                        width="100%"
                        height="300"
                        title="Mapa z lokalizacją"
                        frameBorder="0"
                        scrolling="no"
                        marginHeight="0"
                        marginWidth="0"
                        src="https://www.openstreetmap.org/export/embed.html?bbox=21.0078%2C52.2285%2C21.0158%2C52.2311&layer=mapnik&marker=52.2298%2C21.0118"
                        className="rounded shadow"
                    />
                </div>
            </div>
        </div>
    );
}
